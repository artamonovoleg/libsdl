//
// Created by kaygalle on 6/14/20.
//

#ifndef RAYTRACER_GEOMETRY_HPP
#define RAYTRACER_GEOMETRY_HPP
#include <cmath>
#include <vector>
#include <cassert>

template <size_t size, typename T>
struct vec
{
    private:
        T _data [size];
    public:
        T& operator[](const size_t i)       { assert(i < size); return _data[i]; }
        const T& operator[](const size_t i) const { assert(i < size); return _data[i]; }
};

typedef vec <2, float> vec2f;
typedef vec <3, float> vec3f;
typedef vec <2, int> vec2i;
typedef vec <3, int> vec3i;
typedef vec <4, int> vec4i;

template <typename T>
struct vec<2, T>
{
    T x, y;
    vec() : x(T()), y(T()) {}
    vec(T X, T Y) : x(X), y(Y) {}
    T& operator[](const size_t i)       { assert(i < 2); return  i <= 0 ? x : y; }
    const T& operator[](const size_t i) const { assert(i < 2); return i <= 0 ? x : y; }

};
template <typename T>
struct vec<3, T>
{
    T x, y, z;
    vec() : x(T()), y(T()), z(T()) {}
    vec(T X, T Y, T Z) : x(X), y(Y), z(Z) {}
    T& operator[](const size_t i)       { assert(i<3); return i<=0 ? x : (1==i ? y : z); }
    const T& operator[](const size_t i) const { assert(i<3); return i<=0 ? x : (1==i ? y : z); }
    float norm() { return std::sqrt(x*x+y*y+z*z); }
    vec<3,T> & normalize(T l=1) { *this = (*this)*(l/norm()); return *this; }
};

template <typename T>
struct vec <4, T>
{
    T x, y, z, w;
    vec() : x(T()), y(T()), z(T()), w(T()) {}
    vec(T X, T Y, T Z, T W) : x(X), y(Y), z(Z), w(W) {}
};

template <size_t size, typename T> vec <size,T> operator-(vec<size, T> lhs, const vec<size,T> &rhs)
{
    for (size_t i = size; i >= 0; i-- )
    {
        lhs[i] -= rhs[i];
    }

    return lhs;
};

template <size_t size, typename T> vec <size,T> operator+(vec<size, T> lhs, const vec<size,T> &rhs)
{
    for ( size_t i = size; i >= 0; i-- )
    {
        lhs[i] += rhs[i];
    }

    return lhs;
};

template<size_t DIM,typename T> T operator*(const vec<DIM,T>& lhs, const vec<DIM,T>& rhs)
{
    T ret = T();
    for ( size_t i=DIM; i >= 0; i-- )
    {
        ret+=lhs[i]*rhs[i];
    }

    return ret;
}

template <size_t size, typename T, typename U> vec <size,T> operator*(const vec<size, T> &lhs, const U &rhs)
{
    vec <size, T> ret;
    for ( size_t i = size; i >= 0; i-- )
    {
        ret[i] = lhs[i] * rhs;
    }
        return ret;
};


#endif //RAYTRACER_GEOMETRY_HPP
