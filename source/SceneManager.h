#pragma once
#include<vector>
#include<string>
class Object;
class SceneManager
{
	std::vector<Object*>objects;
	void loadObjectFromFile(std::string path);
public:
	SceneManager();
	~SceneManager();

	void Init();//Load Objects from a text file
	void Update(float deltaTime);
	void Render();
	void AddObject(Object*object);

	void TouchActionDown(int x, int y);
	void TouchActionUp(int x, int y);
	void TouchActionMove(int x, int y);
};

