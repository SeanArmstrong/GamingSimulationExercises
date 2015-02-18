#pragma once
#include <iostream>
#include "Vector3.h"
#include "GameTimer.h"

class Calculator
{
public:
	Calculator();
	~Calculator();


	Vector3 ExplicitEuler() const;
	Vector3 ImplicitEuler() const;
	Vector3 SemiImplicitEuler() const;

	Vector3 CalculateFinalVector() const;
	Vector3 CalculateDisplacementVector() const;

	Vector3 VectorViaUserInput() const;
};

