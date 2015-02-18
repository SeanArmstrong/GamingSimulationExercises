#pragma once
#include <Windows.h>

class GameTimer
{
public:
	GameTimer();
	~GameTimer();
	float getTime();
	float getTime(LARGE_INTEGER start, LARGE_INTEGER frequency);
	float deltaTime();


private:
	LARGE_INTEGER startTime;
	LARGE_INTEGER frequency;
	float previousTime;
	//float fFreq;
};

