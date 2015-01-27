#pragma once;

#include "Entity.h"

//Default Constructor
Entity::Entity(){
	this->position = Vector3();
	this->aggroRange = 0;
	this->entitiesInRange = 0;
}

Entity::Entity(float x, float y, float z, float aggRange){
	this->position = Vector3(x, y, z);
	this->aggroRange = aggRange;
	this->entitiesInRange = 0;
}


Entity::~Entity()
{
}


bool Entity::inRange(const Vector3& epos) const {
	float xDistance = abs(this->position.getCoordinateX() - epos.getCoordinateX());
	float yDistance = abs(this->position.getCoordinateY() - epos.getCoordinateY());
	float zDistance = abs(this->position.getCoordinateZ() - epos.getCoordinateZ());

	if (xDistance > this->aggroRange || yDistance > this->aggroRange || zDistance > this->aggroRange)
	{
		return false;
	}

	return (xDistance*xDistance + yDistance*yDistance + zDistance*zDistance) <= (this->aggroRange*this->aggroRange);
}

bool Entity::inRange2(const Vector3& epos) const {
	Vector3 directionVector = position - epos;

	if (directionVector.getCoordinateX() > this->aggroRange || 
		directionVector.getCoordinateY() > this->aggroRange || 
		directionVector.getCoordinateZ() > this->aggroRange)
	{
		return false;
	}

	return (directionVector.getCoordinateX()*directionVector.getCoordinateX() + 
			directionVector.getCoordinateY()*directionVector.getCoordinateY() + 
			directionVector.getCoordinateZ()*directionVector.getCoordinateZ()) <= (this->aggroRange*this->aggroRange);
}

std::ostream& operator<< (std::ostream& outStream, Entity e){
	outStream << "Position: " << e.getPosition() << " AggroRange: " << e.getAggroRange() << " Entities in Range: " << e.getEntitiesInRange();
	return outStream;
}