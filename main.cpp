#include "SquareMat.h"
#include <iostream>
using namespace matrix;

int main()
{
    {
        // create an array of values with size of 5X5
        double values[5][5] = {
            {1.5, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}};
            
        SquareMat a(5, (double *)values); // create a 5X5 matrix with the values
        SquareMat b(5);
        std::cout << a << std::endl;

        a = a+a;
        std::cout << a << std::endl;
        a = a-(a/2);
        std::cout << a << std::endl;
        a = -a;
        std::cout << a << std::endl;
        a = a*a;
        std::cout << a << std::endl;
        a = a*2;
        std::cout << a << std::endl;
        a = (0.5)*a;
        std::cout << a << std::endl;

        a = a%2;
        std::cout << a << std::endl;
        a = a%a;
        std::cout << a << std::endl;

        a = a^2;
        std::cout << a << std::endl;

        a = a/(0.5);
        std::cout << a << std::endl;

        b = a++;
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        b = a--;
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        
        b = ++a;
        std::cout << b << std::endl;
        std::cout << a << std::endl;

        b = --a;
        std::cout << b << std::endl;
        std::cout << a << std::endl;

        a[0][2] = 15;
        std::cout << a << std::endl;
        a = ~a;
        std::cout << a << std::endl;

        a[0][0] = 1444.1;
        std::cout << a << std::endl;

        




    
    }

    
}
