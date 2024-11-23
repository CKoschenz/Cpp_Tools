#include <projectname/factorial/factorial.hpp>

long int factorial(int n) {
    if (n>=1)
        return n*factorial(n-1);
    else
        return 1;
}  