// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#pragma once

#ifndef CS303_ASSIGNMENT2_NONPROFESSIONAL_H
#define CS303_ASSIGNMENT2_NONPROFESSIONAL_H

#endif //CS303_ASSIGNMENT2_NONPROFESSIONAL_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Employees.h"


// Nonprofessional class declarations
class Nonprofessional : public Employee {
private:
	float hoursWorked;
	float hourlyRate = 20.00;

public:
	Nonprofessional();
	Nonprofessional(float hoursWorked);

	void setWeeklySalary();
	void setVacationDays();
	void setHealthContributions();
	void print();
};