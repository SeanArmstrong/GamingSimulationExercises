#pragma once;

#include "Vector3.h"
#include <cmath>

Vector3::Vector3(const float xVal, const float yVal, const float zVal){
	coord[0] = xVal;
	coord[1] = yVal;
	coord[2] = zVal;
}

Vector3::Vector3(const Vector3& v){
	coord[0] = v.coord[0];
	coord[1] = v.coord[1];
	coord[2] = v.coord[2];
}

Vector3::~Vector3(){
}

/* Get Magnitude
* Returns magnitude of vector as a double
*
* Originally used pow(x, 2) but x*x does
* not add to stack
*/
float Vector3::getMagnitude() const{
	return sqrt((coord[0] * coord[0]) + (coord[1] * coord[1]) + (coord[2] * coord[2]));
}

float Vector3::getSqrMagintude() const {
	return (coord[0] * coord[0]) + (coord[1] * coord[1]) + (coord[2] * coord[2]);
}

/*
If magintude is NULL will return a
{0,0,0} vector
A exception could be thrown but this
is slow
*/
Vector3 Vector3::unitVector(){
	Vector3 newVector;
	float magnitude = getMagnitude();
	if (magnitude != 0){
		newVector.coord[0] = coord[0] / magnitude;
		newVector.coord[1] = coord[1] / magnitude;
		newVector.coord[2] = coord[2] / magnitude;
	}
	return newVector;
}

Vector3 Vector3::orthogonalUnitVector(const Vector3& v){
	return (*this % v).unitVector();
}

Vector3 Vector3::operator+(const Vector3& v){
	Vector3 newVector;
	newVector.coord[0] = (coord[0] + v.coord[0]);
	newVector.coord[1] = (coord[1] + v.coord[1]);
	newVector.coord[2] = (coord[2] + v.coord[2]);
	return newVector;
}

Vector3 Vector3::operator-(const Vector3& v) const{
	Vector3 newVector;
	newVector.coord[0] = (coord[0] - v.coord[0]);
	newVector.coord[1] = (coord[1] - v.coord[1]);
	newVector.coord[2] = (coord[2] - v.coord[2]);
	return newVector;
}

Vector3 Vector3::operator*(const float scalar){
	Vector3 newVector;
	newVector.coord[0] = (coord[0] * scalar);
	newVector.coord[1] = (coord[1] * scalar);
	newVector.coord[2] = (coord[2] * scalar);
	return newVector;
}

/*
If scalar is 0 will return a
{0,0,0} vector
A exception could be thrown but this
is slow
*/
Vector3 Vector3::operator/(const float scalar){
	Vector3 newVector;
	if (scalar != 0){
		newVector.coord[0] = (coord[0] / scalar);
		newVector.coord[1] = (coord[1] / scalar);
		newVector.coord[2] = (coord[2] / scalar);
	}
	return newVector;
}

float Vector3::operator*(const Vector3& v){
	return ((coord[0] * v.coord[0]) + (coord[1] * v.coord[1]) + (coord[2] * v.coord[2]));
}

Vector3 Vector3::operator%(const Vector3& v){
	Vector3 newVector;
	newVector.coord[0] = ((coord[1] * v.coord[2]) - (coord[2] * v.coord[1]));
	newVector.coord[1] = ((coord[2] * v.coord[0]) - (coord[0] * v.coord[2]));
	newVector.coord[2] = ((coord[0] * v.coord[1]) - (coord[1] * v.coord[0]));
	return newVector;
}

Vector3& Vector3::operator+=(const Vector3& v){
	coord[0] = coord[0] + v.coord[0];
	coord[1] = coord[1] + v.coord[1];
	coord[2] = coord[2] + v.coord[2];
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v){
	coord[0] = coord[0] - v.coord[0];
	coord[1] = coord[1] - v.coord[1];
	coord[2] = coord[2] - v.coord[2];
	return *this;
}

Vector3& Vector3::operator/=(const float scalar){
	if (scalar != 0){
		coord[0] = coord[0] / scalar;
		coord[1] = coord[1] / scalar;
		coord[2] = coord[2] / scalar;
	}
	return *this;
}

Vector3& Vector3::operator%=(const Vector3& v){
	coord[0] = ((coord[1] * v.coord[2]) - (coord[2] * v.coord[1]));
	coord[1] = ((coord[2] * v.coord[0]) - (coord[0] * v.coord[2]));
	coord[2] = ((coord[0] * v.coord[1]) - (coord[1] * v.coord[0]));
	return *this;
}

bool Vector3::operator==(const Vector3& v) const {
	return ((coord[0] == v.coord[0]) && (coord[1] == v.coord[1]) && (coord[2] == v.coord[2]));
}

bool Vector3::operator!=(const Vector3& v) const {
	return (!(*this == v));
}

Vector3& Vector3::operator=(const Vector3& v) {
	coord[0] = v.coord[0];
	coord[1] = v.coord[1];
	coord[2] = v.coord[2];
	return *this;
}

Vector3 operator*(const float scalar, Vector3& v){
	return (v * scalar);
}

std::ostream& operator<< (std::ostream& outStream, Vector3 vector){
	outStream << "{" << vector.getCoordinateX() << ", " <<
		vector.getCoordinateY() << ", " <<
		vector.getCoordinateZ() << "}";

	return outStream;
}