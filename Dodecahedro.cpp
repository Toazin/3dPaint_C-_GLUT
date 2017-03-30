#include "Dodecahedro.h"

DodecahedroGL::DodecahedroGL() : ObjectGL() {
	this->type = 9;	
}
DodecahedroGL::~DodecahedroGL() {
}

void DodecahedroGL::render() {
	glPushMatrix();

	glColor3f(this->color[0], this->color[1], this->color[2]);

	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);

	if (this->style == GL_LINE) {
		glutWireDodecahedron();
	}
	else {
		glutSolidDodecahedron();
	}

	glPopMatrix();
}