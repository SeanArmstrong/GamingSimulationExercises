#include "Calculator.h"


Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}

Vector3 Calculator::ExplicitEuler() const{
	// v2 = v1 + a1*(deltaT)
	// s2 = s1 + v1(deltaT)
	return NULL;
}

Vector3 Calculator::ImplicitEuler() const{
	return NULL;

}

Vector3 Calculator::SemiImplicitEuler() const{
	return NULL;

}


Vector3 Calculator::CalculateFinalVector() const{
	float t;
	Vector3 v, u, a;

	std::cout << "The system will take 7 inputs" << std::endl;
	std::cout << "3 for initial Vector, 3 for acceleration Vector and a time value" << std::endl;
	std::cout << "\nEnter the values for the Intial Vector" << std::endl;
	u = VectorViaUserInput();
	std::cout << "\nEnter the values for the acceleration" << std::endl;
	a = VectorViaUserInput();
	std::cout << "\nEnter the values for time\n time: ";
	std::cin >> t;

	std::cout << "\nUsing v = u + at" << std::endl;
	std::cout << "Initial Vector = " << u << std::endl;
	std::cout << "Acceleration Vector = " << a << std::endl;
	std::cout << "time = " << t << std::endl;

	v = u + (a*t);

	std::cout << "Final Vector = " << v << std::endl;
	return v;
}

Vector3 Calculator::CalculateDisplacementVector() const{
	float t;
	Vector3 s, u, a;

	std::cout << "The system will take 7 inputs" << std::endl;
	std::cout << "3 for initial Vector, 3 for acceleration Vector and a time value" << std::endl;
	std::cout << "\nEnter the values for the Intial Vector" << std::endl;
	u = VectorViaUserInput();
	std::cout << "\nEnter the values for the acceleration" << std::endl;
	a = VectorViaUserInput();
	std::cout << "\nEnter the values for time\n time: ";
	std::cin >> t;

	std::cout << "\nUsing s = ut + 0.5*a*(t^2)" << std::endl;
	std::cout << "Initial Vector = " << u << std::endl;
	std::cout << "Acceleration Vector = " << a << std::endl;
	std::cout << "time = " << t << std::endl;

	s = (u*t) + (0.5*a*t*t);
	std::cout << "Displacement Vector = " << s << std::endl;
	return s;
}

Vector3 Calculator::VectorViaUserInput() const{
	float x, y, z;
	std::cout << "x: ";
	std::cin >> x;
	std::cout << "\ny: ";
	std::cin >> y;
	std::cout << "\nz: ";
	std::cin >> z;

	return Vector3(x, y, z);
}
