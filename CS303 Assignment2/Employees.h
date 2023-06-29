// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#pragma once

#ifndef CS303_ASSIGNMENT2_EMPLOYEES_H
#define CS303_ASSIGNMENT2_EMPLOYEES_H

#endif //CS303_ASSIGNMENT2_EMPLOYEES_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Employees.h"

// Employee class declarations
class Employee {
protected:
	float weeklyPay;
	float vacationDays;
	float healthContributions;

public:
	Employee();                            //constructor: default
	Employee(float hourlyPay);   //constructor: overloaded

	// Virtual void definitions for use by derived classes Professional and Nonprofessional
	virtual void print() = 0;
	virtual void setWeeklySalary() = 0;
	virtual void setVacationDays() = 0;
	virtual void setHealthContributions() = 0;
};
