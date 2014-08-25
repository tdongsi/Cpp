#include "Problem002.h"
#include <iostream>

void projecteuler::solutions::solve_problem002()
{
    long sum = 0;
    long first = 1;
    long second = 2;
    long third = first + second;
    long max = 4000000L;

    while ( second < max )
    {
        // The even value Fibonacci number is the second of every three numbers.
        sum += second;

        // print out for checking
        if ( third  < 300 )
        {
            std::cout << first << " " << second << " " << third << std::endl;
        }

        // Generate the next three
        first = second + third;
        second = third + first;
        third = first + second;
    }

    std::cout << "The sum is " << sum << std::endl;

    return;
}
