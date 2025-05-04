#include "SquareMat.h"
#include <stdexcept>
#include <cmath>

namespace matrix
{
    // Default constructors
    SquareMat::SquareMat()
    {
        size = 0;
        mat = nullptr;
    };

    // This is a construcr which initialize an empty SquareMat with specific size.
    // @param size: size of the matrix
    SquareMat::SquareMat(size_t size)
    {
        this->size = size;

        mat = new double *[size];

        for (size_t i = 0; i < size; i++)
        {
            mat[i] = new double[size]{0};
        }
    }
    SquareMat::SquareMat(size_t size, double values[])
    {
        // if (size * size != sizeof(values) / sizeof(double))
        // {
        //     throw std::invalid_argument("number of values doesnt not match matrix size/");
        // }
        this->size = size;

        mat = new double *[size];

        for (size_t i = 0; i < size; i++)
        {
            mat[i] = new double[size];
            for (size_t j = 0; j < size; j++)
            {
                mat[i][j] = values[i * size + j];
            }
        }
    }
    SquareMat::SquareMat(const SquareMat &other)
    {
        this->size = other.size;

        mat = new double *[size];

        for (size_t i = 0; i < size; i++)
        {
            mat[i] = new double[size];
            for (size_t j = 0; j < size; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
    };
    // Copy assignment operator
    SquareMat &SquareMat::operator=(const SquareMat &other)
    {
        // Avoid self-assignment
        if (this == &other)
            return *this;

        // Clean up existing mat if exists
        if (this->mat)
        {
            for (size_t i = 0; i < size; i++)
            {
                delete[] mat[i];
            }
            delete[] mat;
        }

        this->size = other.size;

        mat = new double *[size];

        for (size_t i = 0; i < size; i++)
        {
            mat[i] = new double[size];
            for (size_t j = 0; j < size; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }

        return *this;
    }
    // Destructor
    SquareMat::~SquareMat()
    {
        if (mat)
        {
            for (size_t i = 0; i < size; i++)
            {
                delete[] mat[i];
            }

            delete[] mat;
        }
    };
    // Access operator
    double *SquareMat::operator[](size_t i)
    {
        if (i < size)
        {
            return mat[i];
        }

        else
            throw std::invalid_argument("Index is out of bounds");
    };

    // compare operators
    bool SquareMat::operator==(const SquareMat &other) const
    {
        long long sum_a = 0;
        long long sum_b = 0;

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; i < size; i++)
            {
                sum_a += mat[i][j];
            }
        }

        for (size_t i = 0; i < other.size; i++)
        {
            for (size_t j = 0; i < other.size; i++)
            {
                sum_b += other.mat[i][j];
            }
        }

        return sum_a == sum_b;
    }
    bool SquareMat::operator!=(const SquareMat &other) const { return !(*this == other); }
    bool SquareMat::operator>=(const SquareMat &other) const { return !(*this < other); }
    bool SquareMat::operator<=(const SquareMat &other) const { return !(*this > other); }
    bool SquareMat::operator<(const SquareMat &other) const
    {
        long long sum_a = 0;
        long long sum_b = 0;

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                sum_a += mat[i][j];
            }
        }

        for (size_t i = 0; i < other.size; i++)
        {
            for (size_t j = 0; j < other.size; j++)
            {
                sum_b += other.mat[i][j];
            }
        }

        return sum_a < sum_b;
    }
    bool SquareMat::operator>(const SquareMat &other) const { return !(*this < other) && !(*this == other); }

    SquareMat SquareMat::operator*(const SquareMat &other) const
    {
        if (this->size != other.size)
        {
            throw std::logic_error("Square matrices should be at the same size;");
        }

        SquareMat temp(size);

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                double sum = 0;
                for (size_t k = 0; k < size; k++)
                {
                    sum += mat[i][k] * other.mat[k][j];
                }

                temp[i][j] = sum;
            }
        }

        return temp;
    }

    SquareMat &SquareMat::operator+=(const SquareMat &other)
    {
        if (size != other.size)
        {
            throw std::logic_error("Cannot apply addition on merices with diffrenet sizes.");
        }
        for (size_t i = 0; i < other.size; i++)
        {
            for (size_t j = 0; j < other.size; j++)
            {
                mat[i][j] += other.mat[i][j];
            }
        }

        return *this;
    }

    SquareMat &SquareMat::operator-=(const SquareMat &other)
    {
        if (size != other.size)
        {
            throw std::logic_error("Cannot apply substracion on merices with diffrenet sizes.");
        }
        for (size_t i = 0; i < other.size; i++)
        {
            for (size_t j = 0; j < other.size; j++)
            {
                mat[i][j] -= other.mat[i][j];
            }
        }

        return *this;
    }
    SquareMat &SquareMat::operator*=(const SquareMat &other)
    {

        SquareMat a = (*this) * other; // calculate the multiplication
        *this = a;                     // copy result to this;

        return *this;
    }
    SquareMat &SquareMat::operator%=(const SquareMat &other)
    {
        *this = *this % other;
        return *this;
    }
    SquareMat &SquareMat::operator*=(double scalar)
    {
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                mat[i][j] *= scalar;
        return *this;
    }
    SquareMat &SquareMat::operator%=(int scalar)
    {

        *this = *this % scalar;
        return *this;
    }

    SquareMat SquareMat::operator%(const SquareMat &other) const
    {
        if (size != other.size)
            throw std::logic_error("Matrices must be the same size for element-wise modulo.");

        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result[i][j] = mat[i][j] * other.mat[i][j];
        return result;
    }
    SquareMat SquareMat::operator*(double scalar) const
    {
        SquareMat temp(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                temp[i][j] = mat[i][j] * scalar;
        return temp;
    }
    SquareMat SquareMat::operator/(double scalar) const
    {
        if (scalar == 0)
            throw std::invalid_argument("Division by zero.");

        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result[i][j] = mat[i][j] / scalar;
        return result;
    }
    SquareMat SquareMat::operator~() const
    {
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result[j][i] = mat[i][j];
        return result;
    }
    SquareMat SquareMat::operator-() const
    {
        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result[i][j] = -mat[i][j];
        return result;
    }
    SquareMat SquareMat::operator+(const SquareMat &other) const
    {
        if (size != other.size)
        {
            throw std::logic_error("Cannot add matrices of different sizes.");
        }

        SquareMat result(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                result[i][j] = mat[i][j] + other.mat[i][j];
        return result;
    }

    SquareMat SquareMat::operator-(const SquareMat &other) const
    {
        if (size != other.size)
        {
            throw std::logic_error("Cannot subtract matrices of different sizes.");
        }

        SquareMat temp(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                temp[i][j] = mat[i][j] - other.mat[i][j];
        return temp;
    }

    SquareMat &SquareMat::operator++()
    {
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                ++mat[i][j];
        return *this;
    }

    SquareMat &SquareMat::operator--()
    {
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                --mat[i][j];
        return *this;
    }

    SquareMat SquareMat::operator++(int)
    {
        SquareMat temp(*this);
        ++(*this);
        return temp;
    }

    SquareMat SquareMat::operator--(int)
    {
        SquareMat temp(*this);
        --(*this);
        return temp;
    }
    std::ostream &operator<<(std::ostream &os, const SquareMat &matrix)
    {
        for (size_t i = 0; i < matrix.size; ++i)
        {
            for (size_t j = 0; j < matrix.size; ++j)
            {
                os  << matrix.mat[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
    SquareMat SquareMat::operator^(int power) const
    {
        if (power < 0)
            throw std::invalid_argument("Negative exponent not supported.");

        SquareMat temp(size);
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size; ++j)
                temp[i][j] = (i == j) ? 1 : 0;

        SquareMat base(*this);
        while (power > 0)
        {
            if (power % 2 == 1)
                temp *= base;
            base *= base;
            power /= 2;
        }
        return temp;
    }
    double SquareMat::operator!()
    {
        if (size == 1)
            return mat[0][0];
        if (size == 2)
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

        double det = 0.0;
        for (size_t k = 0; k < size; ++k)
        {
            SquareMat sub(size - 1);
            for (size_t i = 1; i < size; ++i)
            {
                int colIdx = 0;
                for (size_t j = 0; j < size; ++j)
                {
                    if (j == k)
                        continue;
                    sub[i - 1][colIdx++] = mat[i][j];
                }
            }
            det += (k % 2 == 0 ? 1 : -1) * mat[0][k] * !sub;
        }
        return det;
    }

    SquareMat SquareMat::operator%(int scalar) const
    {
        SquareMat temp(*this);

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                temp[i][j] = fmod(mat[i][j], scalar);
            }
        }

        return temp;
    }
    SquareMat operator*(double a, SquareMat &other)
    {
        return other * a;
    }

}
