#pragma once
//
//  Sphere.hpp
//  rigid_simul
//
//  Created by ¿Ã¿Á«ˆ on 2020/10/17.
//
#include <stdio.h>
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>


class Sphere {


public:

    Sphere(float radius, glm::vec3 pos, glm::vec3 vel, glm::vec3 color): restitution(0.5f), mass(1.0f),radius(radius),position(pos),velocity(vel),color(color) {

        obj = gluNewQuadric();
        gluQuadricDrawStyle(obj, GLU_FILL); // <2>
        gluQuadricNormals(obj, GLU_SMOOTH); // <3>
        gluQuadricOrientation(obj, GLU_OUTSIDE); // <4>
        gluQuadricTexture(obj, GL_FALSE); // <5>


   
        acceleration = glm::vec3(0, 0, -9.8f);
        
      
    }

    GLUquadricObj* obj;
    float restitution;
    float mass;
    float radius;


    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 position;
    glm::vec3 color;


    void render() {



        //render sphere
        glPushMatrix();
        glColor3f(color.r, color.g, color.b);
        glTranslatef(position.x, position.y, position.z);
        gluSphere(obj, radius, 24, 24); // position
        glPopMatrix();

    } //rendering method
    void dump();  //for debuging



};


