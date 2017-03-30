#ifndef WORK_SPACE_H
#define WORK_SPACE_H

#include "object_gl.h"
#include <list>
#include <string>

class WorkSpace 
{
public:
	WorkSpace();
	~WorkSpace();
	std::list<ObjectGL *> getAll();
	void addFigure(int type, float x, float y);
	ObjectGL * getSelected();
	void setSelected(int index);
	int getIndex();
	int getType();
	void deleteItem();
};

#endif
