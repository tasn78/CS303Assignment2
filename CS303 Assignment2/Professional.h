// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#pragma once

#ifndef CS303_ASSIGNMENT2_PROFESSIONAL_H
#define CS303_ASSIGNMENT2_PROFESSIONAL_H

#endif //CS303_ASSIGNMENT2_PROFESSIONAL_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Employees.h"
#include "Professional.h"


//Professional class definitions
class Professional : public Employee {
private:
	float salary;
	

public:
	Professional();
	Professional(float yearlySalary);

	void setWeeklySalary();
	void setVacationDays();
	void setHealthContributions();
	void print();
};