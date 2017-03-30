#include "Disk.h"

DiskGL::DiskGL() : ObjectGL() {
	this->style = GL_LINE;
	this->type = 13;
	this->size = 2.f;
	this->inner = 0.01f; 
	this->outer = 1.f;
	this->slices = 50;
	this->loops = 30;
}
DiskGL::~DiskGL() {
}

void DiskGL::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	//drawWireDisk();
	GLUquadric *obj = gluNewQuadric();
	gluQuadricDrawStyle(obj, this->style);
	gluDisk(obj, this->inner, this->outer, this->slices, this->loops);

	glPopMatrix();
}
