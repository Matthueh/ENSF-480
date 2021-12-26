/*
*	File Name: Point.h
*	Assignment Lab 1 exercise D
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Sept 24th 2021
*/

#ifndef POINT_H
#define POINT_H

using namespace std;

class Point{
	
	friend class Human;
	
	private:
		double x;     // x coordinate of a location on Cartisian Plain
		double y;     // y coordinate of a location on Cartisian Plain
	
	public:
	
		//This is the default constructor that will set x and y variables to 0 if no arguments are given.
		Point();
		
		//This is a constructor that will set x and y to a and b respectively.
		Point(double a, double b);
		
		//This is the getter function that will get the coordinate of x.
		double get_x()const;    

		//This is the getter function that will get the coordinate of y.
		double get_y()const; 
		
		//This is setter function that will set the coordinate of x.
		void set_x(double a);
		
		//This is the setter function that will set the coordinate of y.
		void set_y(double a);
};
#endif