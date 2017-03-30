#include "Cylinder.h"
#include "object_gl.h"
#include <math.h>
#include <list>

CylinderGL::CylinderGL() : ObjectGL() {
	this->setStyle(GL_LINE);
	this->type = 12;
	this->size = 2.f;
}
CylinderGL::~CylinderGL() {
}

void CylinderGL::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	// Base circle
	ObjectGL *p = new DiskGL();
	p->setColor(this->color[0], this->color[1], this->color[2]);
	p->style = this->style;
	p->render();

	// Tube
	GLUquadric *obj = gluNewQuadric();
	gluQuadricDrawStyle(obj, this->style);
	gluCylinder(obj, this->size / 2, this->size / 2, this->size, 100, 10);


	// Top circle
	ObjectGL *p2 = new DiskGL();
	p2->setColor(this->color[0], this->color[1], this->color[2]);
	p2->style = this->style;
	p2->traslate(0.f, 0.f, this->size);
	p2->render();

	glPopMatrix();
}