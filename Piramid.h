/*#ifndef PIRAMID_H
#define PIRAMID_H

#include "polygon_gl.h"
#include "triangle_gl.h";
#include "quad_gl.h";

class PiramidGL : public PolygonGL
{
private:
	GLfloat size;
public:
	PiramidGL();
	~PiramidGL();
	void render();
};

#endif
*/
#ifndef PYRAMID_GL_H
#define PYRAMID_GL_H

#include "polygon_gl.h"
#include "quad_gl.h"
#include "triangle_gl.h"

class PiramidGL : public PolygonGL {

private:
	QuadGL *q1;
	TriangleGL *t1, *t2, *t3, *t4;

public:
	PiramidGL();
	~PiramidGL();
	void render();
};

#endif