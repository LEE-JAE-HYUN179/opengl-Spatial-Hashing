#include "Simulator.h"

void Simulator::step()
{
	//explicit
	for (int i = 0; i < sphereList.size(); i++) {
		sphereList[i].velocity += sphereList[i].acceleration * deltaT;
		sphereList[i].position += sphereList[i].velocity * deltaT;
	}

	handler.resolveCollision(sphereList);

}

void Simulator::render()
{
	for (auto& sphere : sphereList) {
		sphere.render();
	}
}


