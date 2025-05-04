# README - Assignment 2: Square Matrix Operator Overloading

## Student Details:

**Name:** \[Shmuel BenAtar]
**Email:** [shmuel.benatar@msmail.ariel.ac.il](mailto:shmuel.benatar@msmail.ariel.ac.il)

---

## Project Overview

This project implements a `SquareMat` class to represent and manipulate square matrices of real numbers.
The assignment demonstrates object-oriented programming concepts, including:

* Operator overloading (arithmetic, logical, unary, and compound operators)
* Memory management using dynamic 2D arrays
* The Rule of Three (constructor, copy constructor, and assignment operator)
* Exception handling for invalid inputs

---

## File Structure

* `SquareMat.h` – Header file defining the `SquareMat` class and its methods
* `SquareMat.cpp` – Implementation of all class methods and operator overloads
* `TestSquareMat.cpp` – Unit tests using the `doctest` framework
* `main.cpp` – A sample demonstration file for manual testing
* `Makefile` – Compilation and automation commands (see below)

---

## Implemented Operators

* Arithmetic operators: `+`, `-`, `*`, `/`, `%`, `^`
* Scalar operations: `matrix * scalar`, `scalar * matrix`, `matrix % int`, `matrix / scalar`
* Unary operators: `-matrix`, `++`, `--`, transpose `~`, determinant `!`
* Assignment operators: `+=`, `-=`, `*=`, `/=`, `%=`
* Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=` (based on sum of matrix elements)
* Element access: `matrix[i][j]`
* Output stream: `operator<<`

---

## Testing

Extensive unit tests were written using `doctest`. Tests include:

* Matrix arithmetic and scalar operations
* Equality and comparison based on element sum
* Edge cases (e.g., modulo with negative values, power of matrix)
* Division, transpose, and validation of operator behavior

---

## Compilation & Execution

The `Makefile` provides the following commands:

* `make Main` – Compiles the main demonstration program
* `make test` – Compiles and runs the unit tests
* `make valgrind` – Checks for memory leaks using Valgrind
* `make clean` – Removes compiled binaries and temporary files

---

## Additional Notes

* The implementation does **not** use STL containers such as `vector` or `stack`, as per the assignment rules.
* Matrices are managed via dynamic 2D arrays (`double**`) with proper memory cleanup.
* Input validation and exception handling are integrated where appropriate.

---