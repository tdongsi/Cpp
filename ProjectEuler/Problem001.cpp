#include "Problem001.h"
#include "Utility.h"
#include <iostream>
#include <cmath>

// The first few problems are too simple to create a class for it

void projecteuler::solutions::solve_problem001()
{
    int sum = 0;

    for (int i=1; i < 1000; i++)
    {
        if ( i % 3 == 0 || i % 5 == 0 )
        {
            sum += i;
        }
    }

    std::cout << "The sum is " << sum << std::endl;

    return;
}


void projecteuler::solutions::solve_problem003()
{
    long long givenNumber = 600851475143LL;
    long sqrtNumber = static_cast<long>( sqrt(givenNumber) );
    std::cout << "sqrtNumber " << sqrtNumber << std::endl;

    for (long i = sqrtNumber; i >= 2; i-- )
    {
        if ( givenNumber % i == 0 && projecteuler::utility::isPrime(i) )
        {
            std::cout << "The largest prime is " << i << std::endl;
            break;
        }
    }

    return;
}


void projecteuler::solutions::solve_problem005()
{
    long product = 2520L;
    long gcd_out = 1;

    for ( long i = 11; i <= 20; i ++ )
    {
        gcd_out = projecteuler::utility::gcd( product, i );

        product *= i/gcd_out;
    }

    std::cout << " The product is " << product << std::endl;

    return;
}
