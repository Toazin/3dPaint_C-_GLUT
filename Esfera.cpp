#include "Esfera.h"

EsferaGL::EsferaGL() : ObjectGL() {
	this->type = 2;
	this->radius = 1.f;
	this->slices = 30.f;
	this->stacks = 30.f;
}
EsferaGL::~EsferaGL() {
}

void EsferaGL::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	if (this->style == GL_LINE) {
		glutWireSphere(this->radius, this->slices, this->stacks);
	}
	else {
		glutSolidSphere(this->radius, this->slices, this->stacks);
	}

	glPopMatrix();
}