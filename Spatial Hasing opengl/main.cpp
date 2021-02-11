//
//  main.cpp
//  rigid_simul
//
//  Created by 이재현 on 2020/10/17.
//

#include <iostream>
#include <GL/glew.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Simulator.h"


GLFWwindow* window;

int WINDOW_WIDTH;
int WINDOW_HEIGHT;

int init() {
    if (!glfwInit()) {
        std::cout << "glfw init failed!!\n";
        return 1;
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


    WINDOW_WIDTH = 2000;
    WINDOW_HEIGHT = 2000;

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Simple Spatial Hashing", NULL, NULL);

    if (!window) {
        std::cout << "window creation failed!\n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);


    glewExperimental = GL_TRUE;

    GLenum errorCode = glewInit();
    if (GLEW_OK != errorCode) {

        glfwTerminate();
        exit(EXIT_FAILURE);
    }



    glClearColor(0.9, 0.9, 0.9, 1.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    return 0;
}

void setCamera() {
    //set camera
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, float(400) / float(400), 0.1, 1000.0);
    gluLookAt(30,20, 20, 0, 0, 0, 0, 0, 1);
    glPopMatrix();

    glFlush();


}


void drawGround() {
    //draw x,y,z, coordinate


    //draw x line
    for (int i = -100; i < 100; i++) {
        glPushMatrix();
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex3f(i*2, -200,0);
        glVertex3f(i*2, 200, 0);
        glEnd();
        glPopMatrix();


    }

    //draw y line
    for (int i = -100; i < 100; i++) {
        glPushMatrix();
        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex3f(-200, 2*i, 0);
        glVertex3f(200, 2*i, 0);
        glEnd();
        glPopMatrix();


    }
    glFlush();



}

void setLight() {

    glPushMatrix();

    // 0번 광원 배치.
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat ambient[4] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat diffuse[4] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat specular[4] = { 0, 0, 0, 0.0 };
    GLfloat position[4] = { -20, -30, 30, 1 };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glPopMatrix();


}



int main(int argc, char** argv) {

    //init glfw and glew 
    init();


    Simulator simulator;


    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        setCamera();
        setLight();
        drawGround();
        simulator.step();
        simulator.render();


        glfwSwapBuffers(window);
        glfwPollEvents();

    }



    return 0;
}
