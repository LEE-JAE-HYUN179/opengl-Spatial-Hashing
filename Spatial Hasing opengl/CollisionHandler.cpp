#include "CollisionHandler.h"

void CollisionHandler::setHashParam(int p1, int p2, int p3, int tableSize, float gridSize)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->n = tableSize;
	this->gridSize = gridSize;
}

void CollisionHandler::mapSphere(vector<Sphere>& sphereList)
{
	for (int i = 0; i < sphereList.size(); i++) {

			
		//¿ÞÂÊ ¿À¸¥ÂÊ ¾Æ·¡À§µµ °ãÄ¥¼ö ÀÖÀ½!!
			int key = calculateKey(sphereList[i].position.x, sphereList[i].position.y, sphereList[i].position.z);


			hashTable[key].push_front(
				MappedSphere{
					i,
					timeStamp
				}
			);


	}

}

int CollisionHandler::calculateKey(float x, float y, float z)
{
	int a1 = ((int)floorf(x / gridSize)) * p1;
	int a2 = ((int)floorf(y / gridSize)) * p2;
	int a3 = ((int)floorf(z / gridSize)) * p3;
	int ret = (a1 ^ a2 ^ a3) % n;

	if (ret < 0) ret += n;
	return ret;
	
}

void CollisionHandler::cleanHashTable()
{

	for (int i = 0; i < n; i++) {
		hashTable[i].clear();
	}
}
