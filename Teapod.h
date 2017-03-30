#ifndef TEAPOD_H
#define TEAPOD_H

#include "object_gl.h"

class TeapodGL : public ObjectGL {
public:
	GLfloat size;
public:
	TeapodGL();
	~TeapodGL();
	void render();
};

#endif 

