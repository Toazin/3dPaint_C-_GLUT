#ifndef CYLINDER_h
#define CYLINDER_h

#include "object_gl.h"
#include "Disk.h"

class CylinderGL : public ObjectGL {
private:
	GLfloat size;
public:
	CylinderGL();
	~CylinderGL();
	void render();
};

#endif