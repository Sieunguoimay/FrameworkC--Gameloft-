#include"RectangleObject.h"
#include"videoDriver.h"
#include"Object.h"

RectangleObject::RectangleObject(float x, float y, float w, float h)
	:Object(x,y)
{
	this->size.set(w, h);
}
RectangleObject::~RectangleObject() {

}

void RectangleObject::Update(float deltaTime) {
	Object::Update(deltaTime);

}
void RectangleObject::Render() {
	VideoDriver::GetInstance()->DrawRect((int)position.x, (int)position.y, (int)size.w, (int)size.h);
}
