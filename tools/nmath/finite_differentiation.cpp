#include <vanderwaals/nmath/finite_differentiation.hpp>

std::vector<double> 
Finite_Differentiation::finite_diff
(unsigned int n, double h, std::vector<double> fct_values){

    if (fct_values.size() < 2*n+1)
        throw std::invalid_argument( 
            "Number of Function values to low for order of differentiation.\
                At least 2*order of diff.+1 function evaluations are required"
        );

    // for the first n values use forward diff
    std::vector<double> firstn(fct_values.begin(),fct_values.begin()+2*n);
    std::vector<double >firstdiff = forward_diff(n,h,firstn);

    // for the last n values use backward diff
    std::vector<double> lastn(fct_values.end()-2*n,fct_values.end());
    std::vector<double >lastdiff = backward_diff(n,h,lastn);

    // for the values from index n to the n-th value before the end use central
    // diff
    std::vector<double >centraldiff = central_diff(n,h,fct_values);

   centraldiff.insert(centraldiff.begin(), firstdiff.begin(), firstdiff.end());
   centraldiff.insert(centraldiff.end(), lastdiff.begin(), lastdiff.end());

   return centraldiff;
}


std::vector<double> 
Finite_Differentiation::enhanced_first_order_diff
(double h, std::vector<double> fct_values){

    if (fct_values.size() < 5)
        throw std::invalid_argument( 
            "Number of Function values to low for first order of enhanced\
            differentiation. At least 5 function evaluations are required."
        );

    // for the first value uses enhanced forward diff
    std::vector<double> firstn(fct_values.begin(),fct_values.begin()+3);
    std::vector<double >firstdiff = forward_diff_enhanced_first_order(h,firstn);

    // for the last value uses enhanced backward diff
    std::vector<double> lastn(fct_values.end()-3,fct_values.end());
    std::vector<double >lastdiff = backward_diff_enhanced_first_order(h,lastn);

    // for the values from index 1 to the 1 value before the end use central 
    // diff
    std::vector<double >centraldiff = central_diff(1,h,fct_values);

   centraldiff.insert(centraldiff.begin(), firstdiff.begin(), firstdiff.end());
   centraldiff.insert(centraldiff.end(), lastdiff.begin(), lastdiff.end());

   return centraldiff;
}


std::vector<double> 
Finite_Differentiation::forward_diff
(unsigned int n, double h, std::vector<double> fct_values){
    
    if (fct_values.size() < n+1)
        throw std::invalid_argument( 
            "Number of Function values to low for order of forward\
            differentiation. At least 'order of diff.+1' function evaluations\
            are required."
    );

    std::vector<unsigned int> binom_coeff = Binomial::getAllCoefficients(n);
    std::vector<double> diff_vector (fct_values.size()-n,0.0);

    for(int i=0; i < fct_values.size()-n; ++i){
        double temp = 0.0;
        for(size_t j = 0; j <= n; ++j){
            temp += std::pow(-1.0,n-j)*binom_coeff[j]*fct_values[i+j];
        }
        diff_vector[i] = temp;
    }

    std::transform(diff_vector.begin(), diff_vector.end(), diff_vector.begin(),
        std::bind(std::multiplies<double>(), std::placeholders::_1, 
        std::pow(h,-double(n))));

    return diff_vector;
}


std::vector<double> 
Finite_Differentiation::forward_diff_enhanced_first_order
(double h, std::vector<double> fct_values){
    
    if (fct_values.size() < 3)
        throw std::invalid_argument( 
            "Number of Function values to low for order of enhanced forward\
            differentiation. At least 3 function evaluations\
            are required."
    );

    std::vector<double> diff_vector (fct_values.size()-2,0.0);

    for(int i=0; i < fct_values.size()-2; ++i){
        diff_vector[i] = - fct_values[i+2] + 4*fct_values[i+1] - 3*fct_values[i];
    }

    std::transform(diff_vector.begin(), diff_vector.end(), diff_vector.begin(),
        std::bind(std::multiplies<double>(), std::placeholders::_1, 1/(2*h)));

    return diff_vector;
}


std::vector<double>
Finite_Differentiation::backward_diff
(unsigned int n, double h, std::vector<double> fct_values){

    if (fct_values.size() < n+1)
        throw std::invalid_argument( 
            "Number of Function values to low for order of backward\
            differentiation. At least 'order of diff.+1' function evaluations\
            are required."
    );

    std::vector<unsigned int> binom_coeff = Binomial::getAllCoefficients(n);
    std::vector<double> diff_vector (fct_values.size()-n,0.0);

    for(int i=n; i < fct_values.size(); ++i){
        double temp = 0.0;
        for(size_t j = 0; j <= n; ++j){
            temp += std::pow(-1.0,j)*binom_coeff[j]*fct_values[i-j];
        }
        diff_vector[i-n] = temp;
    }

    std::transform(diff_vector.begin(), diff_vector.end(), diff_vector.begin(),
        std::bind(std::multiplies<double>(), std::placeholders::_1, 
        std::pow(h,-double(n))));

    return diff_vector;
}


std::vector<double>
Finite_Differentiation::backward_diff_enhanced_first_order
(double h, std::vector<double> fct_values){

    if (fct_values.size() < 3)
        throw std::invalid_argument( 
            "Number of Function values to low for order of enhanced backward\
            differentiation. At least '3' function evaluations\
            are required."
    );

    std::vector<double> diff_vector (fct_values.size()-2,0.0);

    for(int i=2; i < fct_values.size(); ++i){
        diff_vector[i-2] = fct_values[i-2] - 4*fct_values[i-1] + 3*fct_values[i]; 
    }

    std::transform(diff_vector.begin(), diff_vector.end(), diff_vector.begin(),
        std::bind(std::multiplies<double>(), std::placeholders::_1, 1/(2*h)));

    return diff_vector;
}


std::vector<double>
Finite_Differentiation::central_diff
(unsigned int n, double h, std::vector<double> fct_values){

    if (fct_values.size() < 2*n+1)
        throw std::invalid_argument( 
            "Number of Function values to low for order of center\
            differentiation. At least '2*order of diff.+1' function evaluations\
            are required."
    );

    std::vector<unsigned int> binom_coeff = Binomial::getAllCoefficients(n);
    std::vector<double> diff_vector (fct_values.size()-2*n,0.0);

    if(n % 2) { 
        // order of differentiation is odd, use averaging approach to keep the
        // interval length the same
        for(int i=n; i < fct_values.size()-n; ++i){
            double temp = 0.0;
            for(size_t j = 0; j <= n; ++j){
                temp += std::pow(-1.0,j)*binom_coeff[j]
                        *(fct_values[i+((n-1)/2)-j] + fct_values[i+((n+1)/2)-j]);
            }
            diff_vector[i-n] = 0.5*temp;
        }
    } else { // order of differentiation is even
        for(int i=n; i < fct_values.size()-n; ++i){
            double temp = 0.0;
            for(size_t j = 0; j <= n; ++j){
                temp += std::pow(-1.0,j)*binom_coeff[j]*fct_values[i+n/2-j];
            }
            diff_vector[i-n] = temp;
        }
    }

    std::transform(diff_vector.begin(), diff_vector.end(), diff_vector.begin(),
        std::bind(std::multiplies<double>(), std::placeholders::_1, 
        std::pow(h,-double(n))));

    return diff_vector;
}
