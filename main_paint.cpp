// transf_instance_main.cpp
// Transformación de Instancias

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include <iostream>
#include <list>
#include <cmath>

#include "workspace.h"

using namespace std;

// Geometries

list<ObjectGL *> scene;

//Rotaciones 

GLfloat deltaR = .01f;
GLfloat rot = 1.f;

GLfloat x = 0.f;
GLfloat z = 0.f;

// Tamaño de la ventana
GLint width = 800;
GLint height = 800;

// Parámetros de la cámara virtual
GLint mouseButton = 0;
GLboolean mouseRotate = false;
GLboolean mouseZoom = false;
GLboolean mousePan = false;
GLint xClick = 0;
GLint yClick = 0;
GLint xAux = 0;
GLint yAux = 0;
GLfloat rotX = 0.f;
GLfloat rotY = 0.f;
GLfloat panX = 0.f;
GLfloat panY = 0.f;
GLfloat zoomZ = -11.f;


//Workspace
WorkSpace *myWork;

//Scene
list<ObjectGL *> objectList;

//List Management
int index = 0;
ObjectGL * selectedItem;
int origin = 0;

//Displayed text
int typeFigure = 0;
int positionFigure = 0;
string originText = "Coordinate";

//Menu
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
float rightX = 0;
float rightY = 0;

// Función que inicializa el Contexto OpenGL y la geometría de la escena
void init()
{
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glColor3f(1.f, 1.f, 1.f);
}

// Función que se invoca cada vez que se redimensiona la ventana
void resize(GLint w, GLint h)
{
	if (h == 0)
	{
		h = 1;
	}
	width = w;
	height = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.f, (float)width / height, 0.1f, 1000.f);		// Transf. de Proyección en Perspectiva
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, width, height);								// Transf. de Viewport (mapeo al área de dibujo)
}

// Geometría sistema coordenado
void geomCoordSys(GLfloat size)
{
	float currentColor[4];
	glGetFloatv(GL_CURRENT_COLOR, currentColor);

	// Eje X (Rojo)
	glColor3f(1., 0., 0.);
	glBegin(GL_LINES);
	glVertex3f(0., 0., 0.);
	glVertex3f(size, 0., 0.);
	glEnd();

	// Eje Y (Verde))
	glColor3f(0., 1., 0.);
	glBegin(GL_LINES);
	glVertex3f(0., 0., 0.);
	glVertex3f(0., size, 0.);
	glEnd();

	// Eje Z (Azul)
	glColor3f(0., 0., 1.);
	glBegin(GL_LINES);
	glVertex3f(0., 0., 0.);
	glVertex3f(0., 0., size);
	glEnd();

	glColor3f(currentColor[0], currentColor[1], currentColor[2]);
}

string getTypeDescription(int type)
{
	string desc = "";
	switch (type)
	{
	case 2:
		desc = "Esfera";
		break;
	case 3:
		desc = "Cono";
		break;
	case 4:
		desc = "Cubo";
		break;
	case 5:
		desc = "Caja";
		break;
	case 6:
		desc = "Toroide";
		break;
	case 7:
		desc = "Tetrahedro";
		break;
	case 8:
		desc = "Octahedro";
		break;
	case 9:
		desc = "Dodecahedro";
		break;
	case 10:
		desc = "Icosahedro";
		break;
	case 11:
		desc = "Tetera";
		break;
	case 12:
		desc = "Cilindro";
		break;
	case 13:
		desc = "Disco";
		break;
	case 14:
		desc = "Punto";
		break;
	case 15:
		desc = "Linea";
		break;
	case 16:
		desc = "Triángulo";
		break;
	case 17:
		desc = "Quad";
		break;
	case 18:
		desc = "Pirámide";
		break;
	}
	return desc;
}

void displayText2()
{

	positionFigure = myWork->getIndex();
	typeFigure = myWork->getType();
	string typeText = getTypeDescription(typeFigure);
	//cout << "Index: " << index << endl;
	string tmp = " adsad " + originText + " - Object Types:" + typeText + "(" + to_string(typeFigure) + ") - " + to_string(positionFigure);
	glColor3ub(0, 255, 0);
	glRasterPos2i(((width / 2) / 100) - .5, ((height / 2) / 100) - .5);
	for (size_t i = 0; i < tmp.size(); ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, tmp[i]);
	}
	/*glRasterPos2i(((width / 2) / 100) , ((height / 2) / 100) );
	for (size_t i = 0; i < tmp.size(); ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, tmp[i]);
	}*/

	glutPostRedisplay();
}

void displayText()
{
	positionFigure = myWork->getIndex();
	typeFigure = myWork->getType();
	string typeText = getTypeDescription(typeFigure);
	//cout << "Index: " << index << endl;
	string s = originText + " - Object Type:" + typeText + "(" + to_string(typeFigure) + ") - " + to_string(positionFigure);

	glDisable(GL_TEXTURE_2D); //added this
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, height);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(10, 10);
	void * font = GLUT_BITMAP_9_BY_15;
	for (string::iterator i = s.begin(); i != s.end(); ++i)
	{
		char c = *i;
		glColor3d(1.0, 0.0, 0.0);
		glutBitmapCharacter(font, c);
	}
	glMatrixMode(GL_MODELVIEW); //swapped this with...
	glPopMatrix();
	glMatrixMode(GL_PROJECTION); //...this
	glPopMatrix();
	//added this
	glEnable(GL_TEXTURE_2D);

	glutPostRedisplay();
}

void colorSelectedItem()
{
	if (selectedItem != NULL) {
		selectedItem->setColor(0.f, 0.f, 1.f);
	}
	
}

// Función que se invoca cada vez que se dibuja
void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Se limpian los buffers con el color activo definido por glClearColor

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Transformación de vista
	glTranslatef(panX, panY, zoomZ);
	glRotatef(rotY, 1.0, 0.0, 0.0);
	glRotatef(rotX, 0.0, 1.0, 0.0);

	// Escena
	geomCoordSys(2.f);

	objectList = myWork->getAll();

	for (list<ObjectGL *>::iterator it = objectList.begin(); it != objectList.end(); it++)
	{
		(*it)->render();
	}
	
	displayText();
	selectedItem = myWork->getSelected();
	colorSelectedItem();

	glutSwapBuffers();			// Se intercambian buffers
}

void keyboardFunction(unsigned char key, int x, int y)
{
	cout << key << " key press " << "x = " << x << " y = " << y << endl;
	if (selectedItem != NULL) {
		if (key == 'w') {
			selectedItem->traslate(0.f, .2f, 0.f);
			return;
		}
		else	if (key == 's') {
			selectedItem->traslate(0.f, -.2f, 0.f);
			return;
		}
		else	if (key == 'a') {
			selectedItem->traslate(-0.2f, 0.f, 0.f);

			return;
		}
		else	if (key == 'd') {
			selectedItem->traslate(0.2f, 0.f, 0.f);
			return;
		}
		else	if (key == 'q') {
			selectedItem->traslate(0.f, 0.f, 0.2f);
			return;
		}
		else	if (key == 'e') {
			selectedItem->traslate(0.f, 0.f, -0.2f);
			return;
		}
	}

	if (selectedItem != NULL) {
		if (key == 'o') {
			selectedItem->rotate(5, 1.f, 0.f, 0.f);
			return;
		}else if (key == 'l') {
			selectedItem->rotate(5, 0.f, 1.f, 0.f);
			return;
		}
		else if (key == 'i') {
			selectedItem->rotate(-5, 1.f, 0.f, 0.f);
			return;
		}
		else if (key == 'k') {
			selectedItem->rotate(-5, 0.f, 1.f, 0.f);
			return;
		}
	}

	if (selectedItem != NULL) {
		if (key == 'r') {
			myWork->deleteItem();
			return;
		}
	}

	if (selectedItem != NULL) {
		int ty = selectedItem->getType();
		cout << "Type: " << ty << endl;
		GLint deltaS = .2f;
		GLint sx = 1.f;
		GLint sy = 1.f;
		GLint sz = 1.f;
		if (key == 't') {
			selectedItem->scale(1.2f, 1.f, 1.f);
			return;
		}else if (key == 'y') {
			selectedItem->scale(.8f, 1.f, 1.f);
			return;
		}else if (key == 'g') {
			selectedItem->scale(1.f, 1.2f, 1.f);
			return;
		}else if (key == 'h') {
			selectedItem->scale(1.f, .8f, 1.f);
			return;
		}else if (key == 'b') {
			selectedItem->scale(1.f, 1.f, 1.2f);
			return;
		}else if (key == 'n') {
			selectedItem->scale(1.f, 1.f, .8f);
			return;
		}
	}

	if (key == 'c') {
		selectedItem->scale(1.f,2.f,1.f);
	}

	if (selectedItem != NULL) {
		if (key == 'x') {
			selectedItem->setStyle(GL_LINE);
			return;
		}
		else if (key == 'z') {
			selectedItem->setStyle(GL_FILL);
			return;
		}
	}
}

void specialKeyboard(int key, int x, int y) {
	cout << key << " Specialkey press " << "x = " << x << " y = " << y << endl;
	if (key == 100) {
		cout << "index: " << index << endl;
		if (objectList.size() > 0) {
			index = index + 1;
			myWork->setSelected(index);
		}
		return;
	}
	if (key == 102) {
		cout << "index: " << index << endl;
		if (objectList.size() > 0) {
			index = index - 1;
			myWork->setSelected(index);
		}
		return;
	}
	if (key == 112) {
		cout << "SHIFT: " <<  origin << endl;
		if (origin != 1) {
			originText = "Origin";
			origin = 1;
		}
		else {
			originText = "Coordinate";
			origin = 0;
		}
		glutPostRedisplay();
		return;
	}
}

void mouse(int button, int state, int x, int y)
{
	mouseButton = button;
	mouseRotate = false;
	mouseZoom = false;
	mousePan = false;
	xClick = x;
	yClick = y;
	if (button == GLUT_LEFT_BUTTON)
	{
		mouseRotate = true;
		xAux = rotX;
		yAux = rotY;
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		//mouseZoom = true;
		//xAux = zoomZ;
	}
	else if (button == GLUT_MIDDLE_BUTTON)
	{
		mousePan = true;
		xAux = panX;
		yAux = panY;
	}
	
}

void mouseMotion(int x, int y)
{
	if (mouseRotate == true)
	{
		if (mouseButton == GLUT_LEFT_BUTTON)
		{
			if ((x - xClick + xAux) > 360.0)
			{
				xAux = xAux - 360.0;
			}
			if ((x - xClick + xAux) < 0.0)
			{
				xAux = xAux + 360.0;
			}
			if ((y - yClick + yAux) > 360.0)
			{
				yAux = yAux - 360.0;
			}
			if ((y - yClick + yAux) < 0.0)
			{
				yAux = yAux + 360.0;
			}
			rotX = x - xClick + xAux;
			rotY = y - yClick + yAux;
		}
	}
	else if (mouseZoom == true)
	{
		if (mouseButton == GLUT_RIGHT_BUTTON)
		{
			
			//cout << " Value  " << ((x - xClick) / 10.0) + xAux << endl;
			//zoomZ = ((x - xClick) / 10.0) + xAux;
		}
	}
	else if (mousePan == true)
	{
		if (mouseButton == GLUT_MIDDLE_BUTTON)
		{
			panX = ((x - xClick) / 63.0) + xAux;
			panY = ((y - yClick) / (-63.0)) + yAux;
		}
	}
	glutPostRedisplay();
}

void mouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0)
	{
		// Zoom in
		zoomZ = zoomZ + .3;
	}
	else
	{
		// Zoom out
		zoomZ = zoomZ - .3;
	}
	glutPostRedisplay();
	return;
}

//MENU
void menu(int num) {
	//cout << " Menu Press:  " << num << endl;
	switch (num)
	{
	case 0:
		glutDestroyWindow(window);
		exit(0);
		break;
	case 1:
		myWork->deleteItem();
		break;
	default:
		cout << "Coordx: " << rightX << "Coordy: " << rightY << endl;
		cout << "Width: " << width << "Height: " << height << endl;
		//float mouseX = (rightX / width);
		//float mouseY = (rightY / height);
		float mouseX = (-(rightX - (width / 2)) / (1350 / zoomZ));
		float mouseY = ((rightY - (height / 2)) / (1350 / zoomZ));

		float xa = (-(rightX - (width / 2)) / (1350 / zoomZ));
		float ya = ((rightY - (height / 2)) / (1350 / zoomZ));

		cout << "Posx: " << mouseX << "Posy: " << mouseY << endl;
		if (origin == 1) {
			myWork->addFigure(num, 0, 0);
		}
		else {
			myWork->addFigure(num, mouseX, mouseY);
		}
		
		break;
	}
	glutPostRedisplay();
}

void status(int status, int x, int y) {
	cout << "status: " << status << " x: " << x << " y: " << y << endl;
	if (status == 1) {
		rightX = x;
		rightY = y;
	}
	
}

void createMenu(void) {
	//Esfera, Cono, Cubo, Caja, Toroide, Tetrahedro, Octahedro, Dodecahedro, Icosahedro, Tetera

	submenu_id = glutCreateMenu(menu);

	glutAddMenuEntry("Esfera", 2);
	glutAddMenuEntry("Cono", 3);
	glutAddMenuEntry("Cubo", 4);
	glutAddMenuEntry("Caja", 5);
	glutAddMenuEntry("Toroide", 6);
	glutAddMenuEntry("Tetrahedro", 7);
	glutAddMenuEntry("Octahedro", 8);
	glutAddMenuEntry("Dodecahedro", 9);
	glutAddMenuEntry("Icosahedro", 10);
	glutAddMenuEntry("Tetera", 11);

	glutAddMenuEntry("Cilindro", 12);
	glutAddMenuEntry("Disco", 13);

	glutAddMenuEntry("Punto", 14);
	glutAddMenuEntry("Linea", 15);
	glutAddMenuEntry("Triángulo", 16);
	glutAddMenuEntry("Quad", 17);

	glutAddMenuEntry("Pirámide", 18);

	menu_id = glutCreateMenu(menu);

	glutAddMenuEntry("Borrar Seleccion", 1);
	glutAddSubMenu("Dibujar figura", submenu_id);
	glutAddMenuEntry("Salir", 0);     
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMenuStatusFunc(status);
}

int main(GLint argc, GLchar **argv)
{
	// 1. Se crea una ventana y un contexto OpenGL usando GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Instance Transformation");

	// 1.2 Se definen las funciones callback para el manejo de eventos
	glutReshapeFunc(resize);
	glutDisplayFunc(render);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboardFunction);
	glutSpecialFunc(specialKeyboard);
	glutMouseWheelFunc(mouseWheel);
	// 2. Se direcciona a las funciones correctas del API de OpenGL
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "GLEW Error");
		return false;
	}
	//Menu
	createMenu();

	// 3. Se inicializa el contexto de OpenGL y la geometría de la escena
	init();
	

	// 4. Se inicia el ciclo de escucha de eventos
	glutMainLoop();
	return 0;
}