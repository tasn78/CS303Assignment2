// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#include "Employees.h"

Employee::Employee() {
	weeklyPay = 0;
	vacationDays = 0;
	healthContributions = 0;
}

Employee::Employee(float weeklyPay) {
	this->weeklyPay = weeklyPay;
	vacationDays = 0;
	healthContributions = 0;
};