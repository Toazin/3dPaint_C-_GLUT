#include "Cono2.h"

ConoGL2::ConoGL2() : ObjectGL() {
	this->type = 3;
	this->base = 1.f;
	this->height = 1.f;
	this->slices = 30.f;
	this->stacks = 30.f;
}
ConoGL2::~ConoGL2() {
}

void ConoGL2::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	if (this->style == GL_LINE) {
		glutWireCone(this->base, this->height, this->slices, this->stacks);
	}
	else {
		glutSolidCone(this->base, this->height, this->slices, this->stacks);
	}

	glPopMatrix();
}