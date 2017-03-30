#ifndef TORUS_H
#define TORUS_H

#include "object_gl.h"

class TorusGL : public ObjectGL {
private:
	GLfloat innerRadius, outerRadius, nsides, rings;
public:
	TorusGL();
	~TorusGL();
	void render();
};

#endif 
