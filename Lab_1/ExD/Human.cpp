/*
*	File Name: Human.cpp
*	Assignment Lab 1 exercise D
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Sept 24th 2021
*/

#include "Human.h"
#include <cstring>
#include <iostream>

using namespace std;

Human::Human(){
	(*this).name = new char[1];
	(*this).name[0] = '\0';
	location.set_x(0);
	location.set_y(0);
}


Human::Human(const char* name, double x, double y)	
{
	this->name = new char[strlen(name)+1] ;
    strcpy(this ->name, name);
    location.set_x(x);
    location.set_y(y);
}

Human::~Human(){
	delete name;
}


char* Human::get_name(){return name;}


void Human::set_name(char* name){
	this->name = new char[strlen(name)+1];        
    strcpy(this ->name, name);
}


Point Human::get_point() const {return location;}


void Human::display() {                      
    cout << "Human Name: " << name << "\nHuman Location: "
    << location.get_x() << " ,"
    << location.get_y() << ".\n" << endl;
}


