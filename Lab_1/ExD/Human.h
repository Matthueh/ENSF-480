/*
*	File Name: Human.h
*	Assignment Lab 1 exercise D
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Sept 24th 2021
*/

#include "Point.h"
#ifndef HUMAN_H
#define HUMAN_H

using namespace std;

class Human{

private:
    Point location;   // Location of an object of Human on a Cartisian Plain
    char *name;       // Human's name
		
public:
   	
	//Default constructor made for Human. This constructor sets everything to 0 if no arguments are given.
	Human();
	
	//Constructor made for Human. This sets class variables to the ones given by the arguments.
	Human(const char* name, double x, double y);
	
	//This is a destructor that will delete the name that was allocated to heap after the class goes out of scope.
	~Human();
	
	//This is a getter method that gets name of the human.
    char* get_name(); 
	
	//This is a setter method that sets the name of the human.
    void set_name(char* name);
	
	//This is a getter method that gets the location of the human.
    Point get_point() const;
	
	//This is a function that displays the name of the human and their respective location.
    void display();
};
#endif