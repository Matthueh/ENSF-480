/*
*	File Name: shape.h
*	Assignment Lab 3 exercise A
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Oct 15 2021
*/
#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Shape{
	
public:
	Shape(double x,double y, const char *shapeName);
	Shape(const Shape &shape2); 		
	//Shape();
	Shape& operator=(const Shape &RHS_Shape);			
	virtual ~Shape();										
	Point& getOrigin();
	char* getName();
	void display();
	double distance(Shape &other);
	static double distance(Shape &the_shape, Shape &other);
	void set_shapeName(char* shapeName);
	char* get_shapeName();
	void move(double dx, double dy);
	
	

protected:
	Point origin;
	char *shapeName;
};

#endif