#pragma once

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"Object.h"
class RectangleObject :public Object{
	Size size;
public:

	RectangleObject(float x, float y, float w, float h);
	~RectangleObject();

	void Update(float deltaTime);
	void Render();
};
#endif//RECTANGLE_H