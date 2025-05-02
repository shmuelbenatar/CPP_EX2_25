#include "SquareMat.h"
#include <iostream>
using namespace matrix;
int main(int argc, char const *argv[])
{

    {
        SquareMat a;
        SquareMat b;
        a*=5;


        SquareMat d(a);
        b=a; // b = 3x3 , a = 11x11 ; // throw ? 

        
        SquareMat *ptr;


    }

    
}
