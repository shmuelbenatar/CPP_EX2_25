// email:shmuel.benatar@msmail.ariel.ac.il

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.h"
using namespace matrix;

TEST_CASE("Constructor and Access") {
    double values[] = {1, 2, 3, 4};
    SquareMat mat(2, values);
    CHECK(mat[0][0] == 1);
    CHECK(mat[1][1] == 4);
}

TEST_CASE("Copy Constructor") {
    double vals[] = {1, 2, 3, 4};
    SquareMat a(2, vals);
    SquareMat b(a);
    CHECK_EQ(a, b);
}

TEST_CASE("Assignment Operator") {
    double vals[] = {1, 2, 3, 4};
    SquareMat a(2, vals);
    SquareMat b;
    b = a;
    CHECK_EQ(a, b);
}

TEST_CASE("Unary Operators") {
    double vals[] = {1, 2, 3, 4};
    SquareMat a(2, vals);
    SquareMat neg = -a;
    CHECK(neg[0][0] == -1);
    CHECK(neg[1][1] == -4);

    SquareMat scalar_div = a / 2;
    CHECK(scalar_div[0][0] == 0.5);
}


TEST_CASE("Addition and Subtraction") {
    double vals[] = {1, 2, 3, 4};
    SquareMat a(2, vals);
    SquareMat b(2, vals);
    SquareMat sum = a + b;
    SquareMat diff = a - b;
    CHECK(sum[0][0] == 2);
    CHECK(diff[1][1] == 0);
}

TEST_CASE("Multiplication and Scalar") {
    double vals[] = {1, 2, 3, 4};
    SquareMat a(2, vals);
    SquareMat b(2, vals);
    SquareMat prod = a * b;
    CHECK(prod[0][0] == 7);
    CHECK(prod[1][1] == 22);

    SquareMat scalar_prod = a * 2;

    a *= 2;

    CHECK_EQ(a, scalar_prod);
    SquareMat scaled = a * 2;
    CHECK(scaled[0][1] == 8);
}

TEST_CASE("Transpose") {
    double vals[] = {1, 2, 3, 4};
    SquareMat a(2, vals);
    SquareMat trans = ~a;
    CHECK_EQ(trans[0][1], 3);
    CHECK_NE(a,trans);
    CHECK_EQ(~trans, a);
}

TEST_CASE("Determinant and Power") {
    double vals[] = {1, 2, 3, 4};
    SquareMat a(2, vals);
    CHECK((int)!a == -2);

    SquareMat id_pow = a ^ 0;
    CHECK(id_pow[0][0] == 1);
    CHECK(id_pow[1][1] == 1);
}

TEST_CASE("Comparison Operators") {
    double a_vals[] = {1, 1, 1, 1};
    double b_vals[] = {2, 2, 2, 2};
    
    SquareMat a(2, a_vals);
    SquareMat b(2, b_vals);
    SquareMat c = a; 

    CHECK_EQ(a,c);
    CHECK_NE(a,b);
    CHECK_NE(b,c);
    CHECK_LT(a,b);
    CHECK_GT(b,a);
    
}

TEST_CASE("Increment and Decrement") {
    double vals[] = {1, 1, 1, 1};
    SquareMat a(2, vals);
    
    for (int i = 0; i < 5; ++i) {
        a++;
    }
    CHECK(a[0][0] == 6);

}

TEST_CASE("Modulo and Exceptions") {

    double vals[] = {5, 6, 7, 8};
    SquareMat a(2, vals);
    SquareMat mod = a % 3;

    a%= 3;
    CHECK_EQ(a,mod);
    CHECK(mod[0][0] == 2);

    SquareMat b(3);
    CHECK_THROWS(a + b);
    CHECK_THROWS(a * b);
    CHECK_THROWS(a / 0);
}

TEST_CASE("Edge Cases") {
    // Zero matrix
    SquareMat zero(2);
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            CHECK(zero[i][j] == 0);

    // 1x1 matrix
    double val[] = {42};
    SquareMat single(1, val);
    CHECK(single[0][0] == 42);
    CHECK(!single == 42);

    // Very large scalar multiplication
    SquareMat scaled = single * 1e6;
    CHECK(scaled[0][0] == 42e6);

    // Modulo with 1 (should result in 0s)
    SquareMat mod1 = single % 1;
    CHECK(mod1[0][0] == 0);

    // Identity matrix via power 0
    SquareMat id = single ^ 0;
    CHECK(id[0][0] == 1);
}

TEST_CASE("Extreme Edge Cases") {
    // Access out-of-bounds
    SquareMat mat(2);
    CHECK_THROWS(mat[2]);

    // Self-assignment
    double vals[] = {1, 2, 3, 4};
    SquareMat a(2, vals);
    a = a;
    CHECK(a[0][0] == 1);

    // Negative values and modulo
    double neg[] = {-1, -2, -3, -4};
    SquareMat negMat(2, neg);
    SquareMat mod = negMat % 3;
    CHECK(mod[0][0] == fmod(-1, 3));

    // *= vs * consistency
    SquareMat b(2, vals);
    SquareMat result = a * b;
    a *= b;
    CHECK(a[0][0] == result[0][0]);
}