#ifndef ESFERA_H
#define ESFERA_H

#include "object_gl.h"

class EsferaGL : public ObjectGL {
private:
	GLfloat radius, slices, stacks;
public:
	EsferaGL();
	~EsferaGL();
	void render();
};

#endif 
