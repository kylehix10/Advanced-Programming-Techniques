// Kyle Hix
// Copyright 2024
#ifndef _PROGRAM3FUNCTIONS_H_
#define _PROGRAM3FUNCTIONS_H_

int CountAboveAv(const double arr[][10], int rows);

void SortByCol(double arr[][10], int rows, int column, bool order);

void SortByRow(double arr[][10], int rows, int sortRow, bool order);

double MedianInCol(double arr[][10], int rows, int column);

int ModeInCol(double arr[][10], int rows, int column, double arr2[2]);

#endif


