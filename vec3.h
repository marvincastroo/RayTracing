#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public:
        double e[3];
        
        // default constructor: initializes vector 
        vec3() : e{0,0,0} {

        }

        // parametrized constructor: initializes vector w/ specific values
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {

        }

        // getter functions: obtain the values of the vector
        //      const = doesnt modify the object - good practice for read only
        double x() const {return e[0];}
        double y() const {return e[1];}
        double z() const {return e[2];}

        // unary negation operator
        vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]); }
        // read: allows vector access by indexing
        double operator[](int i) const {return e[i]; }
        // read and write: allows modifying
        double& operator[](int i) {return e[i];}

        // assignment operator: a += b where a,b are vec3 instances
        vec3 operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }
        
        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // uses the operator declared above, but with the inverse of t
        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        double length() const {
            return std::sqrt(length_squared());
        }
    
        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }


};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;

// inline is a way to re declare a function without an error
// & means its returning a reference - not a copy

// this section defines complementary behavior, e.g supporting 2*vector, cross, dot products, etc
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif