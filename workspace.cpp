#include <GL\glew.h>
#include <GL\freeglut.h>
#include <cmath>

#include "workspace.h"
#include "quad_gl.h"
#include "triangle_gl.h"
#include "box_gl.h"
#include "Esfera.h"
#include "Cono.h"
#include "Cono2.h"
#include "Torus.h"
#include "Tetrahedron.h"
#include "Octahedron.h"
#include "Dodecahedro.h"
#include "Icosahedron.h"
#include "Teapod.h"
#include "Disk.h"
#include "Cylinder.h"
#include "Piramid.h"
#include "Line.h"
#include <string>
#include <iostream>
#include <typeinfo>

std::list<ObjectGL *> workScene;
ObjectGL * itemSelected;
int indexSelected = 0;

WorkSpace::WorkSpace() 
{
	std::cout << " Me cree " << std::endl;
}
WorkSpace::~WorkSpace()
{

}

std::list<ObjectGL *> WorkSpace::getAll() {
	return workScene;
}
void WorkSpace::addFigure(int type, float x, float y) {
	ObjectGL * tmp;
	switch (type)
	{
	case 2:
		std::cout << " Esfera  " << std::endl;
		tmp = new EsferaGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 3:
		std::cout << "Cono " << std::endl;
		tmp = new ConoGL2();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 4:
		std::cout << "Cubo " << std::endl;
		tmp = new BoxGL();
		tmp->setType(4);
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 5:
		std::cout << " Caja " << std::endl;
		tmp = new BoxGL();
		tmp->setType(5);
		tmp->traslate(x, y, 0.f);
		tmp->scale(1.f, 1.f, 2.f);
		workScene.push_back(tmp);
		break;
	case 6:
		std::cout << " Toroide " << std::endl;
		tmp = new TorusGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 7:
		std::cout << " Tetrahedro " << std::endl;
		tmp = new TetrahedronGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 8:
		std::cout << " Octahedro " << std::endl;
		tmp = new OctahedronGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 9:
		std::cout << " Dodecahedro " << std::endl;
		tmp = new DodecahedroGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 10:
		std::cout << " Icosahedro " << std::endl;
		tmp = new IcosahedronGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 11:
		std::cout << " Tetera " << std::endl;
		tmp = new TeapodGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 12:
		std::cout << " Cilindro " << std::endl;
		tmp = new CylinderGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 13:
		std::cout << " Disco " << std::endl;
		tmp = new DiskGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 14:
		std::cout << " Punto " << std::endl;
		tmp = new EsferaGL();
		tmp->setType(14);
		tmp->traslate(x, y, 0.f);
		tmp->scale(.01f, .01f, .01f);
		workScene.push_back(tmp);
		break;
	case 15:
		std::cout << " Linea " << std::endl;
		tmp = new LineGL();
		tmp->setType(15);
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 16:
		std::cout << " Triángulo " << std::endl;
		tmp = new TriangleGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 17:
		std::cout << " Quad " << std::endl;
		tmp = new QuadGL();
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	case 18:
		std::cout << " Pirámide " << std::endl;
		tmp = new PiramidGL();	
		tmp->traslate(x, y, 0.f);
		workScene.push_back(tmp);
		break;
	}
	if (itemSelected != NULL) {
		itemSelected->setColor(1.f, 1.f, 1.f);
	}
	indexSelected = workScene.size()-1;
	itemSelected = tmp;
	return;
}

ObjectGL * WorkSpace::getSelected() {

	return itemSelected;
}
void WorkSpace::setSelected(int index) {
	if (itemSelected != NULL) {
		itemSelected->setColor(1.f, 1.f, 1.f);
	}
	//Logica para el index.
	if (index < 0) {
		index = index * -1;
	}
	if (workScene.size() > 0)
	{
		if (index >= workScene.size()) {
			std::cout << "index1: " << index << std::endl;
			index = index % workScene.size();
		}
		std::cout << "index: " << index << std::endl;
		std::list<ObjectGL *>::iterator it = workScene.begin();
		std::advance(it, index);
		ObjectGL * tmp = (*it);
		itemSelected = tmp;
		indexSelected = index;
		
	}

}

int  WorkSpace::getIndex() {
	return indexSelected;
}

int WorkSpace::getType() {
	if (itemSelected != NULL) {
		return itemSelected->getType();
	}
	return 0;
}

void WorkSpace::deleteItem()
{
	workScene.remove(itemSelected);
}
