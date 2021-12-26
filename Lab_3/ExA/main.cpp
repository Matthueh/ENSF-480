/*
*	File Name: main.cpp
*	Assignment Lab 3 exercise A
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Oct 15 2021
*/
#include <iostream>
#include "point.h"
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "CurveCut.h"
#include "graphicsWorld.h"
using namespace std;


int main(){
	GraphicsWorld world;
	world.run();
	cout << "End of Main" << endl;
	return 0;
}