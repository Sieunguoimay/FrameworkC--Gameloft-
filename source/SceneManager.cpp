#include "SceneManager.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include"Object.h"
#include"RectangleObject.h"
#include"CircleObject.h"
#include"PlaneObject.h"

SceneManager::SceneManager()
{
	
}


SceneManager::~SceneManager()
{
	for (auto&a : objects)
		delete a;
}

void SceneManager::Init() {//Load Objects from a text file
	loadObjectFromFile("SceneManager.txt");
}
void SceneManager::Update(float deltaTime) {
	float gravity = 200;//pixels per second
	for (auto&a : objects) {
		a->applyForce(a->getMass()*vec2(0, gravity));
		a->Update(deltaTime);
	}
}
void SceneManager::Render() {
	for (auto&a : objects) {
		a->Render();
	}
}
void SceneManager::AddObject(Object*object) {
	objects.push_back(object);
}
void SceneManager::TouchActionDown(int x, int y)
{
	for (auto&a : objects) {
		
	}
}
void SceneManager::TouchActionUp(int x, int y)
{
	for (auto&a : objects) {

	}
}
void SceneManager::TouchActionMove(int x, int y)
{
	for (auto&a : objects) {

	}
}
void SceneManager::loadObjectFromFile(std::string path)
{
	std::ifstream file(path.c_str());
	if (file.is_open()) {
		std::cout << "File opened\n";
		std::string line;
		std::string name;
		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		do {
			buffer >> name;
		} while (name[0] == '/'&&name[1] == '/');
		if (name == "#OBJECT_NUM") {
			int object_number;
			int id;
			std::string type;
		
			buffer >>object_number;
			//objects = std::vector<Object*>(object_number);
			for (int i = 0; i < object_number; i++) {
				buffer >> name;//ID
				buffer >> id;
				buffer >> name;//TYPE
				buffer >> type;
				buffer >> name;//position

				if (type == "RECT") {
					int x, y, w, h;
					buffer >> x;
					buffer.ignore();
					buffer >> y;
					buffer.ignore();
					buffer >> w;
					buffer.ignore();
					buffer>> h;
					AddObject(new RectangleObject(x, y, w, h));

					int vel;
					buffer >> name >> vel;
					objects[i]->setVel(0.0f, -(float)vel);
				}
				else if (type == "CIRCLE") {
					int x, y, r;
					buffer >> x;
					buffer.ignore();
					buffer >> y;
					buffer.ignore();
					buffer >> r;
					AddObject(new CircleObject(x, y, r));

					int vel;
					buffer >> name >> vel;
					std::cout << vel;
					objects[i]->setVel(0.0f,-(float)vel);
				}
				else if (type == "PLANE") {
					int x1,y1,x2,y2;
					buffer >> x1;
					buffer.ignore();
					buffer >> y1;
					buffer.ignore();
					buffer >> x2;
					buffer.ignore();
					buffer >> y2;
					AddObject(new PlaneObject(x1, y1, x2, y2));
				}
			}
		}
	}
}
