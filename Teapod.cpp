#include "Teapod.h"

TeapodGL::TeapodGL() : ObjectGL() {
	this->type = 11;
	this->size = 1.f;
}
TeapodGL::~TeapodGL() {
}

void TeapodGL::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	if (this->style == GL_LINE) {
		glutWireTeapot(this->size);
	}
	else {
		glutSolidTeapot(this->size);
	}

	glPopMatrix();
}