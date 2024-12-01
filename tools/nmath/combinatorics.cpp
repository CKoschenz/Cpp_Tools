#include <vanderwaals/nmath/combinatorics.hpp>

std::vector<unsigned int>Binomial::getKCoefficients(   
    unsigned int n, unsigned int k){

    if( k > n) 
        throw std::runtime_error ("k larger than n");

    std::vector<unsigned int> C (k+1,0);

    // Initialize first element with 1
	C[0] = 1;

	for (unsigned int i = 1; i <= n; i++)
	{
		// using the previous row compute the next row entries of the pascal 
        // triangle from element k till 0 
		for (int j = std::min(i, k); j > 0; j--)
			C[j] = C[j] + C[j - 1];
	}
    return C;
}


unsigned int Binomial::getCoefficient(unsigned int n, unsigned int k){
	return getKCoefficients(n,k)[k];
}


std::vector<unsigned int> Binomial::getAllCoefficients(unsigned int n){
    return getKCoefficients(n,n);
}

/**
 * @brief return factorial
 * 
 * recursive function 
 * if ( n >= 1 )
 *       return n*factorial(n-1);
 * else
 *       return 1;
 * 
 * @param n 
 * @return long unsigned int 
 */
long unsigned int factorial(unsigned int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;

}