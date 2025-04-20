#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

// simple class, often used like structs in C++ for holding data
class hit_record{
    // Object will store information about a ray's intersection with a hittable object
    public:
        point3 p; // likely 3d coordinates where the ray hits the object
        vec3 normal; // surface normal vector at point of intersection
        double t;    // store parameter value along the ray where intersect occurs

};
// Abstract class: a class that cannot be instantiated directly. Serves as a blueprint 
// for other classes that will inherit it. 
class hittable {
    public: 
        
        /*
        The virtual keyword is essential for base classes in an inheritance hierarchy. 
        It ensures that when you delete a pointer to a base class object that is actually pointing 
        to a derived class object, the derived class's destructor is called correctly, preventing memory
        leaks and ensuring proper cleanup.
        */
        // virtual destructor, gets called when a hittable object is destroyed.
        // default implementation of the destructor, handled by compiler. 
        virtual ~hittable() = default;  

        // virtual makes this function polymorphic. Derived classes can provide their own specific implementations
        // returns true if the ray r intersects the hittable object within [ray_tmin, ray_tmax]
        virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
        // =0; at the end signal its a pure virtual function. 
        //      A pure virtual function has no implementation in the class where it's declared
        //      Any class that has a pure virtual function becomes an abstract class, meaning
        //          its instances can't be created directly. 
        //      Derived class must provide an implementation and override for that pure virtual function.
};

#endif