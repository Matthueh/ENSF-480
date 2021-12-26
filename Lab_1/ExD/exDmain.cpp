/*
*	File Name: exDmain.cpp
*	Assignment Lab 1 exercise D
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Sept 24th 2021
*/

#include "Human.h"
#include "Point.h"
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	double x = 2000, y = 3000;
	Human h("Ken Lai", x , y); 

    h.display();
	return 0;
}
