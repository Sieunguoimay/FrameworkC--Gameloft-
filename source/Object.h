#pragma once
#include"../common/include/2d/vec2.h"

class Object {
protected:
	vec2 position;
	vec2 velocity;
	vec2 acceleration;
	float mass;
public:
	Object(float x = 0, float y = 0, float mass = 1);
	virtual ~Object();
	virtual void Update(float deltaTime);
	virtual void Render() = 0;
	
	void applyForce(vec2 force);

	//getters and setters
	vec2 getPos() { return position; }
	void setPos(float x, float y) { this->position.set(x, y); }


	vec2&getVel() { return velocity; }
	void setVel(float x, float y) { this->velocity.set(x, y); }
	
	float getMass() const { return this->mass; }
	void setMass(float mass) { this->mass = mass; }
};
