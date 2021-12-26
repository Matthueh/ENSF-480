/*
*	File Name: Circle.h
*	Assignment Lab 3 exercise A
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Oct 15th 2021
*/
#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle: virtual public Shape{
	
public:
	Circle(double x, double y, double rad,const char *shape_name);
	Circle(const Circle &source);
	~Circle();
	double area();
	double perimeter();
	double getRadius()const;
	void setRadius(double rad);
	void display();
	Circle &operator=(const Circle &Circle_input);

protected:
	double radius;
	
};

#endif