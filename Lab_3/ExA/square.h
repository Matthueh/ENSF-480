/*
*	File Name: square.h
*	Assignment Lab 3 exercise A
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Oct 15 2021
*/
#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : virtual public Shape{
	
	
public:
	Square(double side_a, double x, double y, const char *shapeName);
	Square(const Square &square2);	
	//Square();
	Square& operator=(const Square& RHS_Square);				
	virtual ~Square();
	double area();
	double perimeter();
	double get_side_a() const;
	void set_side_a(double side_a);
	void display();
	
protected:
	double side_a;
};

#endif