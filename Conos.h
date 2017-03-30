#ifndef CONO_H
#define CONO_H

#include "object_gl.h"

class ConoGL : public ObjectGL {
private:
	GLfloat radius, slices, stacks, base, height;
public:
	ConoGL();
	~ConoGL();
	void render();
};

#endif
