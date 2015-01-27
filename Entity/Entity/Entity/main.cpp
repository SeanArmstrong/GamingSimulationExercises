#pragma once;
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Entity.h"
#include "Vector3.h"

float randomFloatInRange(float min, float max);
int randomIntInRange(int min, int max);
void test();

int main(){
	srand(time(NULL));

	// Create a fixed number of entities
	const int NUM_OF_ENTITIES = 20;
	float minPositionValue = 0;
	float maxPositionValue = 100;
	int maxAggroValue = 20;

	Entity entities[NUM_OF_ENTITIES];

	// Setup Entities
	for (int i = 0; i < NUM_OF_ENTITIES; i++){
		entities[i] = Entity(randomFloatInRange(minPositionValue, maxPositionValue),
							 randomFloatInRange(minPositionValue, maxPositionValue), 
							 randomFloatInRange(minPositionValue, maxPositionValue),
							 randomIntInRange(0, maxAggroValue));
	}

	// Loop and check for range
	for (int i = 0; i < NUM_OF_ENTITIES; i++){
		for (int j = 0; j < NUM_OF_ENTITIES; j++){
			if (entities[i].inRange(entities[j].getPosition())){
				entities[i].increaseEntitiesInRange();
			}
		}
	}

	// Print out entities
	for (int i = 0; i < NUM_OF_ENTITIES; i++){
		std::cout << entities[i] << std::endl;
	}

	int x;
	std::cin >> x;
	return 0;
}

float randomFloatInRange(float min, float max){
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

int randomIntInRange(int min, int max){
	return min + rand() / (RAND_MAX / (max - min));
}

void test(){
	Entity e1(1, 1, 1, 10);
	Entity e2(10, 10, 10, 1);

	std::cout << e1 << std::endl;
	std::cout << e2 << std::endl;

	std::cout << "In Range ? " << e1.inRange(e2.getPosition()) << std::endl;
	std::cout << "FINISHED TEST\n\n" << std::endl;
}