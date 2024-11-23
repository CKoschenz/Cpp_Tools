// *****************************************************************************
// Supplementary Functions
// *****************************************************************************
//
//  Purpose/Goal:
//
//  Details/Discussion:
//
//  Licensing:
//
//  Modified:
//
//    14 June 2016
//
//  Author:
//
//    Chris Koschenz
//
//  References:
//
// *****************************************************************************

// +++ Include header
#include <tools/utils/utils.hpp>

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Formatierungsfunktionen
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
template <typename T>
std::string prd(T const x, const int decDigits, const int width) {
    std::stringstream ss;
    ss << std::fixed << std::right;
    ss.fill(' ');        // fill space around displayed #
    ss.width(width);     // set  width around displayed #
    ss.precision(decDigits); // set # places after decimal
    ss << x;
    return ss.str();
}

template std::string prd<int>(int const x, const int decDigits, const int width);
template std::string prd<unsigned int>(unsigned int const x, const int decDigits, const int width);
template std::string prd<size_t>(size_t const x, const int decDigits, const int width);
template std::string prd<double>(double const x, const int decDigits, const int width);
template std::string prd<std::complex<double>>(std::complex<double> const x, const int decDigits, const int width);

std::string center(const std::string s, const int w) {
    std::stringstream ss, spaces;
    int padding = w - s.size();                 // count excess room to pad
    for(int i=0; i<padding/2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str();    // format with padding
    if(padding>0 && padding%2!=0)               // if odd #, add 1 space
        ss << " ";
    return ss.str();
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + progress bar
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void progressbar(unsigned int x, unsigned int n, unsigned int w)
{
    if ( (x != n) && (x % (n/100+1) != 0) ) return;

    float ratio  =  x/(float)n;
    unsigned int   c      =  ratio * w;

    std::cout << std::setw(3) << (int)(ratio*100) << "[";
    for (unsigned int x=0; x<c; x++) std::cout << "=";
    for (unsigned int x=c; x<w; x++) std::cout << " ";
    std::cout << "]\r" << std::flush;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Exit with Error
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ExitWithError(const std::string &error)
{
  std::cout << error;
  std::cin.ignore();
  std::cin.get();
  exit(EXIT_FAILURE);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Minimal Value Comparison
// -----------------------------------------------------------------------
// gives min( X, Y)
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

double minimal_value( double X, double Y)
{
  double return_value;

  // If the difference between X and Y is bigger then 1e-6 compare X and Y and
  // give back the smaller one.
  if( fabs( X - Y) >= 1e-6 )
  {
    if( X < Y)  return_value = X;
    else        return_value = Y;
  }
  else
  {
    // The difference between X and Y is less then 1e-6 so they are treated as
    // equal and one of them is returned, here it's X.
    return_value = X;
  }

  return(return_value);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Color Modifier
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Modifier::Modifier() : code_FG(39), code_BG(49), code_FONT(0) {}
Modifier::Modifier(size_t pCode_FG) : code_FG(pCode_FG), code_BG(49), code_FONT(0) {}
Modifier::Modifier(size_t pCode_FG, size_t pCode_BG, size_t pCode_FONT) :
  code_FG(pCode_FG), code_BG(pCode_BG), code_FONT(pCode_FONT) {}

std::ostream& operator<<(std::ostream& os, const Modifier& mod)
{ return os << "\033[" << mod.code_FONT << ";"
                       << mod.code_BG << ";"
                       << mod.code_FG << "m";}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Template Type to String / String to Type
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Convert T, which should be a primitive, to a std::string.
template <typename T>
std::string T_to_string(T const &val)
{
        std::ostringstream ostr;
        ostr << val;

        return ostr.str();
}

template std::string T_to_string<int>(int const &val);
template std::string T_to_string<unsigned int>(unsigned int const &val);
template std::string T_to_string<size_t>(size_t const &val);
template std::string T_to_string<double>(double const &val);
template std::string T_to_string<std::string>(std::string const &val);

// Convert a std::string to T.
template <typename T>
T string_to_T(std::string const &val)
{
    std::istringstream istr(val);
    T returnVal;
    if (!(istr >> returnVal))
        ExitWithError("CFG: Not a valid " + (std::string)typeid(T).name() + " received!\n");
    return returnVal;
}

template int string_to_T<int>(std::string const &val);
template unsigned int string_to_T<unsigned int>(std::string const &val);
template size_t string_to_T<size_t>(std::string const &val);
template double string_to_T<double>(std::string const &val);
template std::string string_to_T<std::string>(std::string const &val);

bool string_to_T(std::string const &val)
{
    std::istringstream istr(val);
    bool returnVal;
    if (!(istr >> std::boolalpha >> returnVal))
        ExitWithError("CFG: Not a valid " + (std::string)typeid(bool).name() + " received!\n");
    return returnVal;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Time Stamp
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

const std::string currentDateTimeStamp()
{
    time_t     now = time( NULL );
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Comparators
// -----------------------------------------------------------------------------
//
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
atleast_almost_equal(T x, T y)
{   int ulp = 2;
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::fabs(x-y) <= std::numeric_limits<T>::epsilon() * std::fabs(x+y) * ulp
        // unless the result is subnormal
        || std::fabs(x-y) < std::numeric_limits<T>::min();
}

template<class T>
typename std::enable_if<std::numeric_limits<T>::is_integer, bool>::type
atleast_almost_equal(T x, T y)
{
    return x == y;
}

template bool atleast_almost_equal<int>(int x, int y);
template bool atleast_almost_equal<double>(double x, double y);

void show_numerical_limits(){
  std::cout << "Numerical Limits" << std::endl;
  std::cout << "Max INT: " << std::numeric_limits<int>::max() << std::endl;
  std::cout << "Min INT: " << std::numeric_limits<int>::min() << std::endl;
  std::cout << "Max Size_t: " << std::numeric_limits<size_t>::max() << std::endl;
  std::cout << "Min Size_t: " << std::numeric_limits<size_t>::min() << std::endl;
  std::cout << "Max DOUBLE: " << std::numeric_limits<double>::max() << std::endl;
  std::cout << "Min DOUBLE: " << std::numeric_limits<double>::min() << std::endl;
}