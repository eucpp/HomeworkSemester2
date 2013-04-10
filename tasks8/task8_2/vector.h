#pragma once

/**
  * Class implements methods for working with integer vectors.
  * Dimension of vector defined as template parametr.
  */
template <unsigned int N> class Vector
{
public:
    Vector();
    Vector(int* values);
    Vector(const Vector<N>&);
    ~Vector() {}
    bool isNull();
    int& operator[](unsigned int i);
    Vector<N> operator=(Vector<N>& vector);
    Vector<N> operator+(Vector<N> oprnd);
    Vector<N> operator-(Vector<N> oprnd);
    /**
      * Scalar multiplication
      */
    int operator*(Vector<N> oprnd);
    bool operator==(Vector<N>& vector);
private:
    int array[N];
};

template <unsigned int N>
Vector<N>::Vector()
{
    for (int i = 0; i < N; i++)
        array[i] = 0;
}
template <unsigned int N>
Vector<N>::Vector(int* values)
{
    for (unsigned int i = 0; i < N; i++)
        array[i] = values[i];
}
template <unsigned int N>
Vector<N>::Vector(const Vector& vector)
{
    for (unsigned int i = 0; i < N; i++)
        array[i] = vector.array[i];
}
template <unsigned int N>
bool Vector<N>::isNull()
{
    for (unsigned int i = 0; i < N; i++)
        if (array[i] != 0)
            return false;
    return true;
}
template <unsigned int N>
int& Vector<N>::operator[](unsigned int i)
{
    return array[i];
}
template <unsigned int N>
Vector<N> Vector<N>::operator=(Vector<N>& vector)
{
    if (this != &vector)
    {
        for (unsigned int i = 0; i < N; i++)
            array[i] = vector.array[i];
        return *this;
    }
}

template <unsigned int N>
Vector<N> Vector<N>::operator+(Vector<N> oprnd)
{
    Vector<N> result;
    for (unsigned int i = 0; i < N; i++)
        result[i] = array[i] + oprnd.array[i];
    return result;
}
template <unsigned int N>
Vector<N> Vector<N>::operator-(Vector<N> oprnd)
{
    Vector<N> result;
    for (unsigned int i = 0; i < N; i++)
        result[i] = array[i] - oprnd.array[i];
    return result;
}
template <unsigned int N>
int Vector<N>::operator*(Vector<N> oprnd)
{
    int result = 0;
    for (unsigned int i = 0; i < N; i++)
        result += array[i] * oprnd.array[i];
    return result;
}
template <unsigned int N>
bool Vector<N>::operator==(Vector<N>& vector)
{
    for (unsigned int i = 0; i < N; ++i)
        if (array[i] != vector.array[i])
            return false;
    return true;
}
