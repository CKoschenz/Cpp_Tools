// *****************************************************************************
//
//  Purpose/Goal:
//
//  Details/Discussion:
//
//  > ExitWithError finalizes MPI
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
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

// +++ Include Guards

#ifndef SUPPLEMENTARY_FUNCTIONS_H
#define SUPPLEMENTARY_FUNCTIONS_H

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Debug-Praeprozessor-Code
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef DEBUG
#define DEBUG

// 0 - NONE, 1 - LOW, 2 - MEDIUM, 3 - HIGH
#define DEBUGLEVEL 0

#if DEBUGLEVEL < 1
  #define ASSERT(x)
#else
  #define ASSERT(x) \
  if(! (x)) \
  { \
    cout << "Fehler. Annahme " << #x << " ist nicht zutreffend\n"; \
    cout << " in Zeile " << __LINE__ << "\n"; \
    cout << " in Datei " << __FILE__ << "\n"; \
  }
#endif

#if DEBUGLEVEL < 2
  #define EVAL(x)
#else
  #define EVAL(x) \
    cout << #x << ":\t" << x << endl;
#endif

#if DEBUGLEVEL < 3
  #define PRINT(x)
#else
  #define PRINT(x) \
    cout << x << endl;
#endif

#endif

// ++++ Namensraum ++++
//using namespace std;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Libraries
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <cmath>
#include <complex>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>	// setprecision()
#include <limits>
#include <ostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <vector>	//Standard-Vektoren
#include <sstream>	//stellt u.a. ostringstream bereit
#include <typeinfo> //typeid(T)

#include "CMAKE_config.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Formatierungsfunktionen
// -----------------------------------------------------------------------------
// http://stackoverflow.com/questions/14765155/how-can-i-easily-format-my-data-table-in-c
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Convert double to string with specified number of places after the decimal
// and left padding.
template <typename T>
std::string prd(T const x, const int decDigits, const int width);

// Center-aligns string within a field of width w. Pads with blank spaces
// to enforce alignment.

std::string center(const std::string s, const int w);

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + progress bar
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void progressbar(unsigned int x, unsigned int n, unsigned int w = 50);

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Exit with Error
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ExitWithError(const std::string &error);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Minimal Value Comparison
// -----------------------------------------------------------------------
// gives min( X, Y)
// threshold = 1e-6
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

double minimal_value( double X, double Y);

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Color Modifier
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class Modifier
{
    size_t code_FG;
    size_t code_BG;
    size_t code_FONT;
  public:
    Modifier();
    Modifier(size_t pCode_FG);
    Modifier(size_t pCode_FG, size_t pCode_BG, size_t pCode_FONT);
    friend std::ostream& operator<<(std::ostream& os, const Modifier& mod);
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Template Type to String / String to Type
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

template <typename T> std::string T_to_string(const T &val);
template <typename T> T string_to_T(const std::string &val);
bool string_to_T(const std::string &val);

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Time Stamp
// -----------------------------------------------------------------------------
// https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

const std::string currentDateTimeStamp();

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Comparators
// -----------------------------------------------------------------------------
//
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type atleast_almost_equal(T x, T y);

template<class T>
typename std::enable_if<std::numeric_limits<T>::is_integer, bool>::type atleast_almost_equal(T x, T y);

/**
 * @brief Print numerical limits
 * 
 */
void show_numerical_limits();

#endif
