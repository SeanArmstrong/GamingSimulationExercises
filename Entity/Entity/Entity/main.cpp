#pragma once;
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Entity.h"
#include "Vector3.h"
#include "Calculator.h"
#include "GameTimer.h"

float randomFloatInRange(float min, float max);
int randomIntInRange(int min, int max);
void testCollisions();
void testCalculator();
void testGameTimer();
void testMovingEntity();

int main(){
	//testCalculator();
	//testCollisions();
	//testGameTimer();
	testMovingEntity();

	int x;
	std::cout << "\nEnter a number to quit" << std::endl;
	std::cin >> x;
	return 0;
}

void testMovingEntity(){
	LARGE_INTEGER freqeuncy, start;
	QueryPerformanceFrequency(&freqeuncy);
	QueryPerformanceCounter(&start);
	GameTimer gt;

	Entity e(1.0f, 1.0f, 1.0f, 10.0f, 10.0f, Vector3(3.0f, 3.0f, 3.0f));
	std::cout << e << std::endl;

	for (int i = 0; i < 10; i++){
		e.update(1);
		if (i == 0){
			e.applyNewForce(Vector3(0, 0, 0));
		}
		std::cout << e << std::endl;
	}

}

void testGameTimer(){
	GameTimer g;
	std::cout << g.getTime() << std::endl;
	std::cout << g.getTime() << std::endl;
	std::cout << g.getTime() << std::endl;
}

void testCalculator(){
	Calculator cal;
	cal.CalculateFinalVector();
	cal.CalculateDisplacementVector();
}

void testCollisions(){
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
			if (entities[i].inRange2(entities[j].getPosition())){
				entities[i].increaseEntitiesInRange();
			}
		}
	}

	// Print out entities
	for (int i = 0; i < NUM_OF_ENTITIES; i++){
		std::cout << entities[i] << std::endl;
	}
}

float randomFloatInRange(float min, float max){
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

int randomIntInRange(int min, int max){
	return min + rand() / (RAND_MAX / (max - min));
}