#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray{
    public: 
        // default constructor
        ray() {

        }
        // parameterized constructor
        //      const point3& origin: reference to a point3 object, starting point of the ray
        //      const vec3& direction: reference to vec3 object, 
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {

        }
        
        // getter method: accessing a variable without the possibility of modifying it outside the class
        const point3& origin() const {
            return orig;
        }
        const vec3& direction() const {
            return dir;
        }
        // calculates the point along the ray at a given parameter "t"
        point3 at(double t) const {
            return orig + t*dir;
        }
    private:
        point3 orig;
        vec3 dir;

};
#endif
