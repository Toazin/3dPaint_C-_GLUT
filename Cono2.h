#ifndef CONO2_H
#define CONO2_H

#include "object_gl.h"

class ConoGL2 : public ObjectGL {
private:
	GLdouble base, height;
	GLint slices, stacks;
public:
	ConoGL2();
	~ConoGL2();
	void render();
};

#endif 
