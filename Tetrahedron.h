#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "object_gl.h"

class TetrahedronGL : public ObjectGL {
public:
	TetrahedronGL();
	~TetrahedronGL();
	void render();
};

#endif 
