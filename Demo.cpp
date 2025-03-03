#include<square_mat.hpp>
#include <iostream>

using namespace std;

int main() {
    ariel::SquareMat mat1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    ariel::SquareMat mat2({{9, 8, 7}, {6, 5, 4}, {3, 2, 1}});

    cout << mat1 - mat2 << endl;
    // Expected output: 
    // -8 -6 -4 
    // -2 0 2 
    // 4 6 8 

    cout << -mat1 << endl;
    // Expected output: 
    // -1 -2 -3 
    // -4 -5 -6 
    // -7 -8 -9 

    cout << ~mat1 << endl;
    // Expected output: 
    // 1 4 7 
    // 2 5 8 
    // 3 6 9

    cout << mat1 % mat2 << endl;
    // Expected output:
    // 9 16 21 
    // 24 25 24 
    // 21 16 9 

    cout << mat1 / 2 << endl;
    // Expected output: 
    // 0.5 1 1.5 
    // 2 2.5 3 
    // 3.5 4 4.5 

    cout << mat1 % 3 << endl;
    // Expected output:
    // 1 2 0
    // 1 2 0
    // 1 2 0

    cout << (mat1 ^ 2) << endl;
    // Expected output: 
    // 30 36 42
    // 66 81 96
    // 102 126 150
    
    cout << (mat1 != mat2) << endl;
    // Expected output: false 

    cout << (mat1 < mat2) << endl;
    // Expected output: false

    cout << (mat1 > mat2) << endl;
    // Expected output: false
    
    cout << (mat1 == mat2) << endl;
    // Expected output: true

    cout << !mat1 << endl;
    // Expected output: 0 
}
