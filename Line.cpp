#include "Line.h"

LineGL::LineGL() : ObjectGL() {

}
LineGL::~LineGL() {
	this->type = 15;
}

void LineGL::render() {
	glColor3f(this->color[0], this->color[1], this->color[2]);
	glPushMatrix();
	//Hace una multiplicación del vector.
	GLfloat *ptrM = glm::value_ptr(this->m);
	glMultMatrixf(ptrM);
	//glLineWidth(1.f);

	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(15, 0, 0);
	glEnd();
	glPopMatrix();

}