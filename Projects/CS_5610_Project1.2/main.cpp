#include <GL/glut.h>


void myDisplay() {

	//clear the viewport
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	
	//OpenGL draw call here

	//Swap buffers
	glutSwapBuffers();
}

void myKeyboard(unsigned char key, int x, int y) {
	//Handle Keyboard input here
	switch (key) {
	case 27:
		exit(0);
	}
}

void myKeyboard2(int key, int x, int y) {
	//Handle keyboard input here
}

void myMouse(int button, int state, int x, int y) {
	//Handle mouse button here
}

void myIdle() {
	//Handle animations here
	float r = (float(rand()) / float((RAND_MAX)));
	float g = (float(rand()) / float((RAND_MAX)));
	float b = (float(rand()) / float((RAND_MAX)));
	glClearColor(r, g, b, 0);
	Sleep(200);

	//Tell GLUT to redraw
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	/*---------------------------------------------------------------------------------------------------
	HERE BEGINS GLUT INITIALIZATIONS---------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/
	int red = 1;
	//This is going to initialize glut
	glutInit(&argc, argv);

	//To create a window we use the followings instructions
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(100, 100);
	//Before to start out windows we can specify some properties about the GLUT API
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGBA| GLUT_DEPTH);
	glutCreateWindow("Hello World");

	//To draw in a window we need to specify to GLUT the function we want to use to draw something
	glutDisplayFunc(myDisplay);

	//We also need other function for the inputs
	//Register Keyboard callback function
	glutKeyboardFunc(myKeyboard);
	//Register special keyboard callback
	glutSpecialFunc(myKeyboard2);

	//We also need to get the mouse bottons
	//Register mouse callback function
	glutMouseFunc(myMouse);

	//Register idle callback function
	glutIdleFunc(myIdle);

	/*---------------------------------------------------------------------------------------------------
	HERE ENDS GLUT INITIALIZATIONS-----------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------------------------------
	HERE BEGINS OPENGL INITIALIZATIONS-------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/
	
	//set the background color
	glClearColor(0, 0, 0, 0);

	//create buffers
	//create textures
	//compile shaders

	/*---------------------------------------------------------------------------------------------------
	HERE ENDS OPENGL INITIALIZATIONS-------------------------------------------------------------------
	----------------------------------------------------------------------------------------------------*/

	glutMainLoop();

	return 0;
}