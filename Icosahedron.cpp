#include "Icosahedron.h"

IcosahedronGL::IcosahedronGL() : ObjectGL() {
	this->type = 10;
}
IcosahedronGL::~IcosahedronGL() {
}

void IcosahedronGL::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	if (this->style == GL_LINE) {
		glutWireIcosahedron();
	}
	else {
		glutSolidIcosahedron();
	}

	glPopMatrix();
}