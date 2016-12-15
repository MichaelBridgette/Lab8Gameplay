#include "Game.h"

static bool flip;

Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube VBO")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex;

Vertex vertex[36];
GLubyte triangles[36];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */


	vertex[0].coordinate[0] = v1.GetXf();
	vertex[0].coordinate[1] = v1.GetYf();
	vertex[0].coordinate[2] = v1.GetZf();

	vertex[1].coordinate[0] = v2.GetXf();
	vertex[1].coordinate[1] = v2.GetYf();
	vertex[1].coordinate[2] = v2.GetZf();

	vertex[2].coordinate[0] = v3.GetXf();
	vertex[2].coordinate[1] = v3.GetYf();
	vertex[2].coordinate[2] = v3.GetZf();

	vertex[3].coordinate[0] = v4.GetXf();
	vertex[3].coordinate[1] = v4.GetYf();
	vertex[3].coordinate[2] = v4.GetZf();

	vertex[4].coordinate[0] = v5.GetX();
	vertex[4].coordinate[1] = v5.GetY();
	vertex[4].coordinate[2] = v5.GetZ();

	vertex[5].coordinate[0] = v6.GetX();
	vertex[5].coordinate[1] = v6.GetY();
	vertex[5].coordinate[2] = v6.GetZ();

	vertex[6].coordinate[0] = v7.GetX();
	vertex[6].coordinate[1] = v7.GetY();
	vertex[6].coordinate[2] = v7.GetZ();

	vertex[7].coordinate[0] = v8.GetX();
	vertex[7].coordinate[1] = v8.GetY();
	vertex[7].coordinate[2] = v8.GetZ();


	
	vertex[0].color[0] = 0.1f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.2f;
	vertex[1].color[1] = 1.0f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;

	vertex[6].color[0] = 1.0f;
	vertex[6].color[1] = 0.0f;
	vertex[6].color[2] = 0.0f;

	vertex[7].color[0] = 0.0f;
	vertex[7].color[1] = 0.0f;
	vertex[7].color[2] = 1.0f;

	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;

	triangles[3] = 0;   triangles[4] = 2;   triangles[5] = 3;

	triangles[6] = 1;   triangles[7] = 5;   triangles[8] = 6;

	triangles[9] = 1;   triangles[10] = 2;   triangles[11] = 6;

	triangles[12] = 3;   triangles[13] = 2;   triangles[14] = 6;

	triangles[15] = 3;   triangles[16] = 7;   triangles[17] = 6;

	triangles[18] = 0;   triangles[19] = 1;   triangles[20] = 5;

	triangles[21] = 0;   triangles[22] = 4;   triangles[23] = 5;

	triangles[24] = 4;   triangles[25] = 7;   triangles[26] = 6;

	triangles[27] = 4;   triangles[28] = 5;   triangles[29] = 6;

	triangles[30] = 0;   triangles[31] = 4;   triangles[32] = 7;

	triangles[33] = 0;   triangles[34] = 3;   triangles[35] = 7;



	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	std::system("cls");
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	

	v1 = m1*v1;
	v2 = m1*v2;
	v3 = m1*v3;
	v4 = m1*v4;
	v5 = m1*v5;
	v6 = m1*v6;
	v7 = m1*v7;
	v8 = m1*v8;

	vertex[0].coordinate[0] = v1.GetXf();
	vertex[0].coordinate[1] = v1.GetYf();
	vertex[0].coordinate[2] = v1.GetZf();

	vertex[1].coordinate[0] = v2.GetXf();
	vertex[1].coordinate[1] = v2.GetYf();
	vertex[1].coordinate[2] = v2.GetZf();

	vertex[2].coordinate[0] = v3.GetXf();
	vertex[2].coordinate[1] = v3.GetYf();
	vertex[2].coordinate[2] = v3.GetZf();

	vertex[3].coordinate[0] = v4.GetXf();
	vertex[3].coordinate[1] = v4.GetYf();
	vertex[3].coordinate[2] = v4.GetZf();

	vertex[4].coordinate[0] = v5.GetX();
	vertex[4].coordinate[1] = v5.GetY();
	vertex[4].coordinate[2] = v5.GetZ();

	vertex[5].coordinate[0] = v6.GetX();
	vertex[5].coordinate[1] = v6.GetY();
	vertex[5].coordinate[2] = v6.GetZ();

	vertex[6].coordinate[0] = v7.GetX();
	vertex[6].coordinate[1] = v7.GetY();
	vertex[6].coordinate[2] = v7.GetZ();

	vertex[7].coordinate[0] = v8.GetX();
	vertex[7].coordinate[1] = v8.GetY();
	vertex[7].coordinate[2] = v8.GetZ();

	v1 = m2*v1;
	v2 = m2*v2;
	v3 = m2*v3;
	v4 = m2*v4;
	v5 = m2*v5;
	v6 = m2*v6;
	v7 = m2*v7;
	v8 = m2*v8;

	vertex[0].coordinate[0] = v1.GetXf();
	vertex[0].coordinate[1] = v1.GetYf();
	vertex[0].coordinate[2] = v1.GetZf();

	vertex[1].coordinate[0] = v2.GetXf();
	vertex[1].coordinate[1] = v2.GetYf();
	vertex[1].coordinate[2] = v2.GetZf();

	vertex[2].coordinate[0] = v3.GetXf();
	vertex[2].coordinate[1] = v3.GetYf();
	vertex[2].coordinate[2] = v3.GetZf();

	vertex[3].coordinate[0] = v4.GetXf();
	vertex[3].coordinate[1] = v4.GetYf();
	vertex[3].coordinate[2] = v4.GetZf();

	vertex[4].coordinate[0] = v5.GetX();
	vertex[4].coordinate[1] = v5.GetY();
	vertex[4].coordinate[2] = v5.GetZ();

	vertex[5].coordinate[0] = v6.GetX();
	vertex[5].coordinate[1] = v6.GetY();
	vertex[5].coordinate[2] = v6.GetZ();

	vertex[6].coordinate[0] = v7.GetX();
	vertex[6].coordinate[1] = v7.GetY();
	vertex[6].coordinate[2] = v7.GetZ();

	vertex[7].coordinate[0] = v8.GetX();
	vertex[7].coordinate[1] = v8.GetY();
	vertex[7].coordinate[2] = v8.GetZ();



	v1 = m3*v1;
	v2 = m3*v2;
	v3 = m3*v3;
	v4 = m3*v4;
	v5 = m3*v5;
	v6 = m3*v6;
	v7 = m3*v7;
	v8 = m3*v8;

	vertex[0].coordinate[0] = v1.GetXf();
	vertex[0].coordinate[1] = v1.GetYf();
	vertex[0].coordinate[2] = v1.GetZf();

	vertex[1].coordinate[0] = v2.GetXf();
	vertex[1].coordinate[1] = v2.GetYf();
	vertex[1].coordinate[2] = v2.GetZf();

	vertex[2].coordinate[0] = v3.GetXf();
	vertex[2].coordinate[1] = v3.GetYf();
	vertex[2].coordinate[2] = v3.GetZf();

	vertex[3].coordinate[0] = v4.GetXf();
	vertex[3].coordinate[1] = v4.GetYf();
	vertex[3].coordinate[2] = v4.GetZf();

	vertex[4].coordinate[0] = v5.GetX();
	vertex[4].coordinate[1] = v5.GetY();
	vertex[4].coordinate[2] = v5.GetZ();

	vertex[5].coordinate[0] = v6.GetX();
	vertex[5].coordinate[1] = v6.GetY();
	vertex[5].coordinate[2] = v6.GetZ();

	vertex[6].coordinate[0] = v7.GetX();
	vertex[6].coordinate[1] = v7.GetY();
	vertex[6].coordinate[2] = v7.GetZ();

	vertex[7].coordinate[0] = v8.GetX();
	vertex[7].coordinate[1] = v8.GetY();
	vertex[7].coordinate[2] = v8.GetZ();



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		

		v1 = scale*v1;
		v2 = scale*v2;
		v3 = scale*v3;
		v4 = scale*v4;
		v5 = scale*v5;
		v6 = scale*v6;
		v7 = scale*v7;
		v8 = scale*v8;

		

		vertex[0].coordinate[0] = v1.GetXf();
		vertex[0].coordinate[1] = v1.GetYf();
		vertex[0].coordinate[2] = v1.GetZf();

		vertex[1].coordinate[0] = v2.GetXf();
		vertex[1].coordinate[1] = v2.GetYf();
		vertex[1].coordinate[2] = v2.GetZf();

		vertex[2].coordinate[0] = v3.GetXf();
		vertex[2].coordinate[1] = v3.GetYf();
		vertex[2].coordinate[2] = v3.GetZf();

		vertex[3].coordinate[0] = v4.GetXf();
		vertex[3].coordinate[1] = v4.GetYf();
		vertex[3].coordinate[2] = v4.GetZf();

		vertex[4].coordinate[0] = v5.GetX();
		vertex[4].coordinate[1] = v5.GetY();
		vertex[4].coordinate[2] = v5.GetZ();

		vertex[5].coordinate[0] = v6.GetX();
		vertex[5].coordinate[1] = v6.GetY();
		vertex[5].coordinate[2] = v6.GetZ();

		vertex[6].coordinate[0] = v7.GetX();
		vertex[6].coordinate[1] = v7.GetY();
		vertex[6].coordinate[2] = v7.GetZ();

		vertex[7].coordinate[0] = v8.GetX();
		vertex[7].coordinate[1] = v8.GetY();
		vertex[7].coordinate[2] = v8.GetZ();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		v1 = translate+v1;
		v2 = translate+v2;
		v3 = translate+v3;
		v4 = translate+v4;
		v5 = translate+v5;
		v6 = translate+v6;
		v7 = translate+v7;
		v8 = translate+v8;



		vertex[0].coordinate[0] = v1.GetXf();
		vertex[0].coordinate[1] = v1.GetYf();
		vertex[0].coordinate[2] = v1.GetZf();

		vertex[1].coordinate[0] = v2.GetXf();
		vertex[1].coordinate[1] = v2.GetYf();
		vertex[1].coordinate[2] = v2.GetZf();

		vertex[2].coordinate[0] = v3.GetXf();
		vertex[2].coordinate[1] = v3.GetYf();
		vertex[2].coordinate[2] = v3.GetZf();

		vertex[3].coordinate[0] = v4.GetXf();
		vertex[3].coordinate[1] = v4.GetYf();
		vertex[3].coordinate[2] = v4.GetZf();

		vertex[4].coordinate[0] = v5.GetX();
		vertex[4].coordinate[1] = v5.GetY();
		vertex[4].coordinate[2] = v5.GetZ();

		vertex[5].coordinate[0] = v6.GetX();
		vertex[5].coordinate[1] = v6.GetY();
		vertex[5].coordinate[2] = v6.GetZ();

		vertex[6].coordinate[0] = v7.GetX();
		vertex[6].coordinate[1] = v7.GetY();
		vertex[6].coordinate[2] = v7.GetZ();

		vertex[7].coordinate[0] = v8.GetX();
		vertex[7].coordinate[1] = v8.GetY();
		vertex[7].coordinate[2] = v8.GetZ();
	}




	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

