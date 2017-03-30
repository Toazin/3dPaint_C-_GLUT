#include "Tetrahedron.h"

TetrahedronGL::TetrahedronGL() : ObjectGL() {
	this->type = 7;
}
TetrahedronGL::~TetrahedronGL() {
}

void TetrahedronGL::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	if (this->style == GL_LINE) {
		glutWireTetrahedron();
	}
	else {
		glutSolidTetrahedron();
	}

	glPopMatrix();
}