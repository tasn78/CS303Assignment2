// Tom Steinman
// CS303-0001
// Created by Owner on 6/24/2023.
// Assignment 2

#include "Nonprofessional.h"

// Default constructor
Nonprofessional::Nonprofessional() {
	hoursWorked = 0;
	weeklyPay = 0;
	vacationDays = 0;
	healthContributions = 0;
}

// Overloaded constructor
Nonprofessional::Nonprofessional(float hoursWorked) : Employee() {
	this->hoursWorked = hoursWorked;
	weeklyPay = 0;
	vacationDays = 0;
	healthContributions = 0;
}

// Sets weekly salary
void Nonprofessional::setWeeklySalary() {
	weeklyPay = hoursWorked * hourlyRate;
}

// Sets vacation days based on hours worked
void Nonprofessional::setVacationDays() {
	vacationDays = hoursWorked * 1.52 / 24.0;
}

// Sets health contributions based on weekly pay (20% of weekly income)
void Nonprofessional::setHealthContributions() {
	healthContributions = this->weeklyPay * 0.20;
}

// Prints Nonprofessional information
void Nonprofessional::print() {
	std::cout << "Employee Type : Nonprofessional" << std::endl;
	std::cout << "Hours worked : " << this->hoursWorked << std::endl;
	std::cout << "Weekly salary : $" << std::fixed << std::setprecision(2) << this->weeklyPay << std::endl;
	std::cout << "Vacation time in hours : " << this->vacationDays << std::endl;
	std::cout << "Health care contributions per week : $" << std::fixed << std::setprecision(2) << this->healthContributions << std::endl << std::endl;
}
;