#include "Problem001.h"
#include "Utility.h"
#include <iostream>
#include <cmath>

// The first few problems are too simple to create a class for it

// Problem 1 has closed-form solution
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

// Problem 6: this has closed-form solution
// By using formula for the sum of the squares of natural numbers,
// and formula for the sum of natural numbers
void projecteuler::solutions::solve_problem006()
{
    long sumOfSquares = 0L;
    long sumOfNumber = 0L;

    for ( long i =1L; i <= 100L; i++ )
    {
        sumOfSquares += (i*i);
        sumOfNumber += i;
    }

    std::cout << "The sumOfSquares is " << sumOfSquares << std::endl;
    long diff = sumOfNumber*sumOfNumber - sumOfSquares;
    std::cout << "The difference is " << diff << std::endl;

    return;
}
