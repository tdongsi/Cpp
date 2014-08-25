#include "Problem001.h"
#include <iostream>

// The first problem is too simple to create a class for it
void projecteuler::problem001::solve_problem001()
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
