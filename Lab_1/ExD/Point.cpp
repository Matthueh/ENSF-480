/*
*	File Name: Point.cpp
*	Assignment Lab 1 exercise D
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Sept 24th 2021
*/

#include <cstring>
#include <iostream>
#include "Point.h"
#include "Human.h"

using namespace std;

Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(double a, double b): x(a), y(b){}

double Point::get_x()const{return x;}	

double Point::get_y()const{return y;}	

void Point::set_x(double a) { x = a;}

void Point::set_y(double a) { y = a;}
