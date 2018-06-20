#include"CircleObject.h"
#include"videoDriver.h"
CircleObject::CircleObject(float x, float y, float radius)
	:Object(x,y),radius(radius)
{
}

CircleObject::~CircleObject() {

}

void CircleObject::Update(float deltaTime) {
	Object::Update(deltaTime);
}
void CircleObject::Render() {
	VideoDriver::GetInstance()->DrawCircle(position.x, position.y, radius);
}
