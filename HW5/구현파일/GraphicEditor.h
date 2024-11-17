#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include <iostream>
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "UI.h"

class GraphicEditor {
	Shape* pStart; 
	Shape* pLast;  
public:
	GraphicEditor(); 
	void insertItem(int type); 
	void deleteItem(int index); 
	void show(); 
	void RunEditor(); 
};

#endif 
