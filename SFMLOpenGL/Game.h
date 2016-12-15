#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>



#include "Vector3.h"
#include "Matrix3.h"

using namespace std;
//using namespace sf;
//using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	sf::Clock clock;
	sf::Time elapsed;

	float rotationAngle = 0.0f;
	Vector3 v1= Vector3(-0.5f, -0.5f, 0.5f);
	Vector3 v2 = Vector3(-0.5f, 0.5f,0.5f);
	Vector3 v3 = Vector3(0.5f,0.5f,0.5f);
	Vector3 v4=Vector3(0.5f,-0.5f,0.5f);
	Vector3 v5=Vector3(-0.5f,- 0.5f,-0.5f);
	Vector3 v6=Vector3(-0.5f,0.5f,-0.5f);
	Vector3 v7=Vector3(0.5f, 0.5f, -0.5f);
	Vector3 v8 = Vector3(0.5f,-0.5f,-0.5f);


	Matrix3 m1 = Matrix3().RotationX(0.5);
	Matrix3 m2 = Matrix3().RotationY(0.5);
	Matrix3 m3 = Matrix3().RotationZ(0.5);

	Vector3 scale = Vector3(1.01, 1.01, 1.01);
	Vector3 translate = Vector3(0.01f, 0.0f, 0.0f);

	Matrix3 m4 = Matrix3().Translate(1,1);
};