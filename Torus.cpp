#include "Torus.h"

TorusGL::TorusGL() : ObjectGL() {
	this->type = 6;
	this->innerRadius = .3f;
	this->outerRadius = .8f;
	this->nsides = 30.f;
	this->rings = 30.f;
}
TorusGL::~TorusGL() {
}

void TorusGL::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	if (this->style == GL_LINE) {
		glutWireTorus(this->innerRadius, this->outerRadius, this->nsides, this->rings);
	}
	else {
		glutSolidTorus(this->innerRadius, this->outerRadius, this->nsides, this->rings);
	}

	glPopMatrix();
}