#include"PlaneObject.h"
#include"videoDriver.h"
PlaneObject::PlaneObject(float x1, float y1, float x2, float y2)
	:Object(x1,y1),position2(x2,y2)
{
}

PlaneObject::~PlaneObject() {

}

void PlaneObject::Update(float deltaTime) {
	//Object::Update(deltaTime);
	//do nothing
}
void PlaneObject::Render() {
	VideoDriver::GetInstance()->DrawLine(position.x, position.y, position2.x, position2.y);
}
