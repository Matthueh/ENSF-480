/*
*	File Name: ExC.cpp
*	Assignment Lab 1 exercise C
*	Completed by: Alexander Sembrat and Matthew Ho
*	Submission Date: Sept 24th 2021
*/

#include <string>
#include <vector>
using namespace std;

// Under regular circumstances each class would have its own file
// but for simplicity's sake we kept all 3 classes in 1 file.

class Company{
	private:
	string companyName;
	string companyAddress;
	string dateEstablished;
	
	vector <Employee> employees;
	vector <Customer> customers;
};

class Employee{
	
	friend class Company;
	
	private:
	string name;
	string address;
	string dateOfBirth;
	string employeeState;
};

class Customer{
	
	friend class Company;
	
	private:
	string name;
	string address;
	string phone;
};
