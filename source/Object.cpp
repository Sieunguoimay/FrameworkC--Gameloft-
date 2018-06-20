#include"Object.h"
Object::Object(float x,float y,float mass)
:position(x,y),mass(mass)
{
	velocity.zero();
	acceleration.zero();
}
Object::~Object() {

}

void Object::Update(float deltaTime) {
	velocity += deltaTime*acceleration;
	position += deltaTime*velocity;
	acceleration.zero();
}

void Object::applyForce(vec2 force)
{
	acceleration += force / mass;
}
