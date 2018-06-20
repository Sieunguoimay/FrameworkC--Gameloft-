#include"Object.h"
class CircleObject :public Object{
	float radius;
public:

	CircleObject(float x, float y, float radius);

	virtual ~CircleObject();

	virtual void Update(float deltaTime);
	virtual void Render();

	void setRadius(float radius) { this->radius = radius;}
	float getRadius()const { return this->radius; }
};