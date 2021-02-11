#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <random>
#include "Sphere.h"
#include "CollisionHandler.h"


class Simulator
{

public:

	Simulator():deltaT(1.f/1200), sphereNum(200),sphereRadius(0.2f),wallMinx(-4),wallMaxx(4),wallMiny(-4),wallMaxy(4) {
		gravity = glm::vec3(0, 0, -9.8f);
		std::random_device rd;

		// engine init
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 999);


		for (int i = 0; i < sphereNum; i++) {
			float posx = ((float)dis(gen)) * (4.f / 999) - 2;
			float posy= ((float)dis(gen)) * (4.f / 999) - 2;
			float posz = ((float)dis(gen)) * (1.f / 999) +4;

			float velx = ((float)dis(gen)) * (4.f / 999) - 2;
			float vely = ((float)dis(gen)) * (4.f / 999) - 2;
			float velz = ((float)dis(gen)) * (0.2f / 999);

			float r = ((float)dis(gen)) * (1.f / 999);
			float g = ((float)dis(gen)) * (1.f / 999);
			float b = ((float)dis(gen)) * (1.f / 999);


			sphereList.push_back(Sphere(sphereRadius,glm::vec3(posx,posy,posz),glm::vec3(velx,vely,velz),glm::vec3(r,g,b)));
			
		}

	};

	std::vector<Sphere> sphereList;

	float deltaT;
	unsigned int sphereNum;
	float sphereRadius;

	float wallMinx;
	float wallMaxx;

	float wallMiny;
	float wallMaxy;

	glm::vec3 gravity;
	CollisionHandler handler;


	void step();

	void render();



private:




};

