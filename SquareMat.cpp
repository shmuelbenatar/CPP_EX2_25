#include "SquareMat.h"
#include <stdexcept>

namespace matrix
{

    SquareMat::SquareMat()
    {
        size = 0;
        mat = nullptr;
    };

    SquareMat::SquareMat(int size)
    {
        this->size = size;

        mat = new double *[size];

        for (int i = 0; i < size; i++)
        {
            mat[i] = new double[size];
        }
    }

    SquareMat::SquareMat(int size, double values[])
    {
        // if (size * size != sizeof(values) / sizeof(double))
        // {
        //     throw std::invalid_argument("number of values doesnt not match matrix size/");
        // }
        this->size = size;

        mat = new double *[size];

        for (int i = 0; i < size; i++)
        {
            mat[i] = new double[size];
            for (int j = 0; j < size; j++)
            {
                mat[i][j] = values[i * size + j];
            }
        }
    }

    double *SquareMat::operator[](int i)
    {
        if (i < size)
        {
            return mat[i];
        }

        else
            throw std::invalid_argument("Index is out of bounds");
    };

    SquareMat::SquareMat(const SquareMat &other)
    {
        this->size = other.size;

        mat = new double *[size];

        for (int i = 0; i < size; i++)
        {
            mat[i] = new double[size];
            for (int j = 0; j < size; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
    };

    SquareMat &SquareMat::operator=(const SquareMat &other)
    {
        if (mat)
        {
            for (int i = 0; i < size; i++)
            {
                delete[] mat[i];
            }
        }

        this->size = other.size;

        mat = new double *[size];

        for (int i = 0; i < size; i++)
        {
            mat[i] = new double[size];
            for (int j = 0; j < size; j++)
            {
                mat[i][j] = other.mat[i][j];
            }
        }

        return *this;
    }

    SquareMat::~SquareMat()
    {
        if (mat)
        {
            for (int i = 0; i < size; i++)
            {
                delete[] mat[i];
            }
        }
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

        return sum_a < sum_b;
    }
    bool SquareMat::operator>(const SquareMat &other) const { return !(*this < other) && !(*this == other); }

    SquareMat SquareMat::operator*(const SquareMat &other) const
    {
        if (this->size != other.size)
        {
            throw std::logic_error("Square matrices should be at the same size;");
        }

        return SquareMat();
    }
}
