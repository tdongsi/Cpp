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

void projecteuler::solutions::solve_problem007()
{
    int count = 2; // count for prime number 2,3
    long number = 3;

    while ( count < 10001 )
    {
        // start checking from number 5
        number+=2;

        if ( projecteuler::utility::isPrime( number ) )
        {
            count++;
        }
    }

    std::cout << "The number is " << number << std::endl;

    return;
}


// Preliminary math analysis gives c in range [409 .. 500]
// c must be less than or equal 500. Otherwise, c^2 > 500^2 > (a+b)^2 > a^2 + b^2.
// c must be greater than or equal 408 since (a+b+c)^2 <= 2((a+b)^2 + c^2) <= 2(2(a^2+b^2)+c^2) = 6c^2 which implies c >= 1000/sqrt(6)
void projecteuler::solutions::solve_problem009()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int sumAB = 0;  // sum of a and b: a+b
    int productAB = 0;  // product of a and b: ab
    int sumSqrAB = 0;   // sum of squares of a and b: a^2 + b^2

    int delta, sqrtDelta;

    for ( c = 409; c <= 500; c++ )
    {
        sumAB = 1000 - c;
        sumSqrAB = c*c;
        productAB = sumAB*sumAB - sumSqrAB;

        if ( productAB % 2 == 1 )
            // product not an integer, no integer solution
            continue;
        else
            productAB /= 2;

        // Solving the quadratic equation x^2 - sumAB*x + productAB = 0
        delta = sumAB*sumAB - 4*productAB;
        sqrtDelta = static_cast<int>( sqrt(delta) );

        if ( (delta - sqrtDelta*sqrtDelta) != 0 )
            // delta not an integer, no integer solution
            continue;
        else {
            if ( (sumAB + sqrtDelta) % 2 == 0 )
            {
                // we have an integer solution
                a = (sumAB + sqrtDelta) /2;
                b = (sumAB - sqrtDelta) /2;
                break;
            }
        }
    }

    std::cout << "a b c: " << a << " " << b << " " << c << std::endl;
    std::cout << " Answer: " << (a*b*c) << std::endl;

    return;
}
