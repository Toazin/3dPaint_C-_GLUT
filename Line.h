#ifndef LINE_H
#define LINE_H

#include "object_gl.h"

class LineGL : public ObjectGL
{
public:
	LineGL();
	~LineGL();
	void render();
};

#endif