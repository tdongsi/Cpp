#include "Utility.h"

bool projecteuler::utility::isPrime( long number )
{
    if ( number < 2 )
        return false;

    // a prime number is divided by 1 and itself
    for (long i=2; i*i <= number; i++)
    {
        if ( number % i == 0 )
        {
            return false;
        }
    }

    return true;
}

long projecteuler::utility::gcd( long a, long b)
{
    long temp = a % b;

    while ( temp != 0 )
    {
        a = b;
        b = temp;
        temp = a%b;
    }

    return b;
}
