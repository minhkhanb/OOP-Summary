#include <GL/glew.h>
#include <GL/freeglut.h>

#pragma comment( lib, "glew32.lib" )
#pragma comment( lib, "freeglut.lib" )
#pragma comment (lib, "OpenGL32.lib")

int width = 640;
int height = 480;

void displayFunc(void);

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
	int id = glutCreateWindow("OpenGL first program");
	glewInit();

	glutDisplayFunc(displayFunc);
	glutMainLoop();
	exit(0);
}

void displayFunc(void)
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}