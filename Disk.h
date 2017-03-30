#ifndef DISK_H
#define DISK_H

#include "object_gl.h"

class DiskGL : public ObjectGL {
private:
	GLdouble inner, outer, slices, loops;
	GLfloat size;
	GLint thickness, stacks;
private:
	void drawDisk();
	void drawWireDisk();
	void drawSolidDisk();
public:
	DiskGL();
	~DiskGL();
	void render();
};

#endif