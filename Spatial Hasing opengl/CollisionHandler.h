#pragma once


#include <glm/glm.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <vector>
#include <list>
#include <algorithm>
#include <cassert>
#include "Sphere.h"


using namespace std;

struct MappedSphere {

	int sphereIndex;
	int timeStamp;
	
};



class CollisionHandler
{

	/*
	* collision detection class using spatial hashing
	*/

public:

	int timeStamp;


	//hash parameter
	int p1, p2, p3;

	int n;//table size

	float gridSize;
	float epsilone;


	//TODO: table initialize 
	CollisionHandler() :p1(73856093), p2(19349663), p3(83492791), n(5000), gridSize(0.3f), timeStamp(0), epsilone(0.0000001) {
		/*
			large prime number
		*/
		for (int i = 0; i < n; i++) hashTable.push_back(list<MappedSphere>());


	};
	~CollisionHandler() {
	};




	void setHashParam(int p1, int p2, int p3, int tableSize, float gridSize);
	void resolveCollision(vector<Sphere>& sphereList);

	//TODO: linked list vs vector 
	vector<list<MappedSphere>> hashTable;

	void mapSphere(vector<Sphere>& sphereList); //timestamp update

	int calculateKey(float x, float y, float z); //if n<0 n+=bucketsize
	bool IsCollide(Sphere& sphere1, Sphere& sphere2);
	void cleanHashTable();

private:



};

