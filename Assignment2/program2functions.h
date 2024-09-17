//Copyright 2024
//KyleHix
//Header File- Assignment 2
#ifndef _PROGRAM2FUNCTIONS_H_
#define _PROGRAM2FUNCTIONS_H_

bool LeapYear(int year);

int LastDayOfMonth(int month, int year=0);

bool ValidDate(int month, int day, int year);

void NextDate(int &month, int &day, int &year);

void PreviousDate(int &month, int &day, int &year);

#endif
