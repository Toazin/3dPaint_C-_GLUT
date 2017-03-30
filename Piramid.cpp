#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>
#include <list>

#include "Piramid.h"

using namespace std;

list<PolygonGL *> pyramid;

PiramidGL::PiramidGL() : PolygonGL() {
	this->type = 18;
	this->style = GL_LINE;
	this->q1 = new QuadGL();
	q1->traslate(0.f, -1 / 6, 0.f);
	q1->rotate(90, 1.f, 0.f, 0.f);

	this->t1 = new TriangleGL();
	t1->traslate(.0f, 0.f, -1 / 3.f);
	t1->rotate(45, 1.f, 0.f, 0.f);

	this->t2 = new TriangleGL();
	t2->traslate(.0f, 0.f, 1 / 3.f);
	t2->rotate(-45, 1.f, 0.f, 0.f);

	this->t3 = new TriangleGL();
	t3->traslate(-1 / 3.f, 0.f, 0.f);
	t3->rotate(90, 0.f, 1.f, 0.f);
	t3->rotate(45, 1.f, 0.f, 0.f);

	this->t4 = new TriangleGL();
	t4->traslate(1 / 3.f, 0.f, 0.0f);
	t4->rotate(90, 0.f, 1.f, 0.f);
	t4->rotate(-45, 1.f, 0.f, 0.f);

	pyramid.push_back(q1);
	pyramid.push_back(t1);
	pyramid.push_back(t2);
	pyramid.push_back(t3);
	pyramid.push_back(t4);


}

PiramidGL::~PiramidGL()
{

}
void PiramidGL::render()
{
	glPushMatrix();
	glPolygonMode(GL_FRONT, this->frontFaceMode);
	glPolygonMode(GL_BACK, this->backFaceMode);
	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);


	glScalef(0.5f, 0.5f, 0.5f);

	glBegin(GL_TRIANGLES); 
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd(); 

	glPopMatrix();
}

/*
#include "Piramid.h"
#include "quad_gl.h"
#include "triangle_gl.h";

PiramidGL::PiramidGL() : PolygonGL()
{
	this->type = 18;
	this->style = GL_LINES;
	this->size = 1;

	
}
PiramidGL::~PiramidGL()
{

}
void PiramidGL::render()
{

	glPushMatrix();
	//Hace una multiplicación del vector.
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	glPushMatrix();
	glTranslatef(0.f, -1.f, 0.f);
	glRotatef(-90, 1.0, 0.0, 0.0);

	glBegin(this->style);
	glVertex3f(0.f, 0.f, this->size * 2);
	glVertex3f(this->size, this->size, 0.0f);
	glEnd();

	glBegin(this->style);
	glVertex3f(0.f, 0.f, this->size * 2);
	glVertex3f(-this->size, this->size, 0.0f);
	glEnd();

	glBegin(this->style);
	glVertex3f(0.f, 0.f, this->size*2);
	glVertex3f(-this->size, -this->size, 0.0f);
	glEnd();

	glBegin(this->style);
	glVertex3f(0.f, 0.f, this->size*2);
	glVertex3f(this->size, -this->size, 0.0f);
	glEnd();

	glBegin(this->style);
	glVertex3f(this->size, this->size, 0.0f);
	glVertex3f(-this->size, this->size, 0.0f);
	glEnd();

	glBegin(this->style);
	glVertex3f(-this->size, this->size, 0.0f);
	glVertex3f(-this->size, -this->size, 0.0f);
	glEnd();

	glBegin(this->style);
	glVertex3f(-this->size, -this->size, 0.0f);
	glVertex3f(this->size, -this->size, 0.0f);
	glEnd();

	glBegin(this->style);
	glVertex3f(this->size, -this->size, 0.0f);
	glVertex3f(this->size, this->size, 0.0f);
	glEnd();
	glPopMatrix();

	/*
	//FrontFace
	this->c1->frontFaceMode = this->frontFaceMode;
	this->c2->frontFaceMode = this->frontFaceMode;
	this->c3->frontFaceMode = this->frontFaceMode;
	this->c4->frontFaceMode = this->frontFaceMode;
	this->c5->frontFaceMode = this->frontFaceMode;
	//backFace
	this->c1->backFaceMode = this->backFaceMode;
	this->c2->backFaceMode = this->backFaceMode;
	this->c3->backFaceMode = this->backFaceMode;
	this->c4->backFaceMode = this->backFaceMode;
	this->c5->backFaceMode = this->backFaceMode;
	//Color
	this->c1->setColor(this->color[0], this->color[1], this->color[2]);
	this->c2->setColor(this->color[0], this->color[1], this->color[2]);
	this->c3->setColor(this->color[0], this->color[1], this->color[2]);
	this->c4->setColor(this->color[0], this->color[1], this->color[2]);
	this->c5->setColor(this->color[0], this->color[1], this->color[2]);


	this->c1->render();
	this->c2->render();
	this->c3->render();
	this->c4->render();
	this->c5->render();
	
	glPopMatrix();
}
*/