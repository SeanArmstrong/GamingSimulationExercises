#pragma once
#pragma once;

#include "Vector3.h"
#include "Entity.h"

class Entity
{
public:
	Entity();
	Entity(float x, float y, float z, float aggRange, float mass = 10, Vector3 force = 0);
	~Entity();

	Vector3 getPosition() const				{ return position; }
	float getAggroRange() const				{ return aggroRange; }
	int getEntitiesInRange() const			{ return entitiesInRange; }

	void updateAggroRange(const float x)	{ aggroRange = x; }
	void updatePosition(const Vector3& pos)	{ position = pos; }
	void updateEntitiesInRange(const int x) { entitiesInRange = x; }
	void increaseEntitiesInRange()			{ entitiesInRange++; }
	void decreaseEntitiesInRange()			{ entitiesInRange--; }

	void applyNewForce(Vector3& force);
	void update(float t);

	bool inRange(const Vector3& epos) const;
	bool inRange2(const Vector3& epos) const;

	
private:
	Vector3		position;
	Vector3		previousPosition;
	Vector3		acceleration;
	float		mass;
	float		aggroRange;
	int			entitiesInRange;
};

std::ostream& operator<< (std::ostream& outStream, Entity e);
