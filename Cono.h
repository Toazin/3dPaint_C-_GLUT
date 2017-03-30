#ifndef CONO_H
#define CONO_H

#include "object_gl.h"

class ConoGL : public ObjectGL {
private:
	GLfloat radius, base, height;
	GLint slices, stacks;
public:
	ConoGL();
	~ConoGL();
	void render();
};

#endif
