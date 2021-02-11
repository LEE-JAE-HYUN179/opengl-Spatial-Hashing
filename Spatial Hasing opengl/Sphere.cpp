#include "Sphere.h"
#include <iostream>





void Sphere::dump() {

    //for debugging

    std::cout << "----------------------------------------------------\n";
    std::cout << "[position] x: " << position.x << " y: " << position.y << " z: " << position.z << "\n";
    std::cout << "[velocity] x: " << velocity.x << " y: " << velocity.y << " z: " << velocity.z << "\n";
    std::cout << "[acc] x: " << acceleration.x << " y: " << acceleration.y << " z: " << acceleration.z << "\n";
    std::cout << "----------------------------------------------------\n";

}
