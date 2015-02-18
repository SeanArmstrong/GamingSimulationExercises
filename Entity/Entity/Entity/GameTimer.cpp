#include "GameTimer.h"


GameTimer::GameTimer(){
	LARGE_INTEGER f, s;
	QueryPerformanceFrequency(&f);
	QueryPerformanceCounter(&s);
	startTime = s;
	frequency = f;
}


GameTimer::~GameTimer(){
}


/*
* From handouts
*/
float GameTimer::getTime() {
	LARGE_INTEGER t;
	QueryPerformanceCounter(&t);
	previousTime = (float)((t.QuadPart - startTime.QuadPart) * 1000.0f / frequency.QuadPart);
	return previousTime;
}

float GameTimer::getTime(LARGE_INTEGER start, LARGE_INTEGER freq) {
	LARGE_INTEGER t;
	QueryPerformanceCounter(&t);
	return (float)((t.QuadPart - start.QuadPart) * 1000.0f / freq.QuadPart);
}

float GameTimer::deltaTime() {
	float temp = previousTime;
	getTime();
	return previousTime - temp;
}

/*

GameTimer::GameTimer(){
LARGE_INTEGER freq;
QueryPerformanceFrequency(&freq);
fFreq = (float)freq.QuadPart;
reset();
}

float GameTimer::getTime() {
	LARGE_INTEGER endTime;
	QueryPerformanceCounter(&endTime);
	previousTime = (endTime.QuadPart - startTime.QuadPart) / fFreq;
	return previousTime;
}



* Possible bug if resetting then getting delta time?

void GameTimer::reset(){
	QueryPerformanceCounter(&startTime);
}

float GameTimer::deltaTime() {
	float temp = previousTime;
	getTime();
	return  previousTime - temp;
}*/