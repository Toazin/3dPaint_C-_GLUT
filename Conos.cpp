#include "Cono.h"

ConoGL::ConoGL() : ObjectGL() {
	this->radius = 50.f;
	this->slices = 50.f;
	this->base = 5.f;
	this->height = 5.f;

}
ConoGL::~ConoGL() {
}

void ConoGL::render() {
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