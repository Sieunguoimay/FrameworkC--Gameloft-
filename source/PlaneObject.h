#include"Object.h"
class PlaneObject :public Object {
	vec2 position2;
public:

	PlaneObject(float x1, float y1,float x2, float y2);

	virtual ~PlaneObject();

	virtual void Update(float deltaTime);
	virtual void Render();

};