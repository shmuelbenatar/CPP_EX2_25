#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "SquareMat.h"

TEST_CASE("Check Multiplication")
{
    matrix::SquareMat a(4);
    matrix::SquareMat b(5);

    CHECK_THROWS(a * b);
    CHECK_NOTHROW(a*b);


}

 TEST_CASE("Addition"){
    
 }