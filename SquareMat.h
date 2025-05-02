#ifndef SQUAREMAT_H
#define SQUAREMAT_H

#include "ostream"
namespace matrix
{

    class SquareMat
    {
    public:
        SquareMat();
        SquareMat(int size);
        SquareMat(int size, double values[]);
        SquareMat(const SquareMat &other);

        SquareMat &operator=(const SquareMat &other);
        ~SquareMat();

        SquareMat operator+(const SquareMat &other) const;
        SquareMat operator-(const SquareMat &other) const;

        // a = -a // unary operator
        SquareMat operator-() const;

        SquareMat operator*(const SquareMat &other) const;
        SquareMat operator*(double scalar) const;

        SquareMat operator%(const SquareMat &other) const;
        SquareMat operator%(int scalar) const;

        SquareMat operator/(double scalar) const;

        SquareMat operator^(int scalar) const;

        SquareMat &operator++(); // post-increment
        SquareMat &operator--(); // post-increment

        SquareMat operator++(int); // pre-increment
        SquareMat operator--(int); // pre-increment

        SquareMat operator~() const;
        double *operator[](int i);

        friend SquareMat operator*(double a, SquareMat &other);

        bool operator==(const SquareMat &other) const;
        bool operator!=(const SquareMat &other) const;

        bool operator>=(const SquareMat &other) const;
        bool operator<=(const SquareMat &other) const;
        bool operator<(const SquareMat &other) const;
        bool operator>(const SquareMat &other) const;

        double operator!();

        SquareMat &operator+=(SquareMat &other);
        SquareMat &operator-=(SquareMat &other);
        SquareMat &operator*=(SquareMat &other);
        SquareMat &operator%=(SquareMat &other);
        SquareMat &operator*=(double scalar);
        SquareMat &operator%=(double scalar);

        friend std::ostream &operator<<(std::ostream &os, const SquareMat &matrix);

    private:
        double **mat;
        int size;
    };

    SquareMat operator*(double a, SquareMat &other);

}

#endif // SQUAREMAT_H
