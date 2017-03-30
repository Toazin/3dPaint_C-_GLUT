#include "Octahedron.h"

OctahedronGL::OctahedronGL() : ObjectGL() {
	this->type = 8;
}
OctahedronGL::~OctahedronGL() {
}

void OctahedronGL::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	if (this->style == GL_LINE) {
		glutWireOctahedron();
	}
	else {
		glutSolidOctahedron();
	}

	glPopMatrix();
}