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


bool Entity::inRange(const Vector3 epos) const {
	float xDistance = this->position.getCoordinateX() - epos.getCoordinateX();
	float yDistance = this->position.getCoordinateY() - epos.getCoordinateY();
	float zDistance = this->position.getCoordinateZ() - epos.getCoordinateZ();
	float distance = (xDistance*xDistance + yDistance*yDistance + zDistance*zDistance);
	return distance <= (this->aggroRange*this->aggroRange);
}

std::ostream& operator<< (std::ostream& outStream, Entity e){
	outStream << "Position: " << e.getPosition() << " AggroRange: " << e.getAggroRange() << " Entities in Range: " << e.getEntitiesInRange();
	return outStream;
}