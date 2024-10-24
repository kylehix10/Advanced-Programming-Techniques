// Kyle Hix
// Copyright 2024
#include "program3functions.h"

int CountAboveAv(const double arr[][10], int rows) {
  int totalNumbers = 0;
  int count = 0;
  double sum = 0.0;
// Counting Number of items and Calculating Sum
for(int i = 0; i < rows; i++) {
for(int j = 0; j < 10; j++) {
  sum += arr[i][j];
  totalNumbers++;
  }
}
// Mean
double mean = sum/totalNumbers;
// Counting Above Mean
for (int i = 0; i < rows; i++) {
  for (int j = 0; j < 10; j++) {
  if (arr[i][j] > mean) {
  count++;
}
}
}
return count;
}  // End of CountAboveAv

void SortByCol(double arr[][10], int rows, int column, bool order) {
// Moving through values
for (int i = 0; i < rows-1; i++) {
  for (int j = 0; j < rows-i-1; j++) {
// Ascending Order
  if (order && arr[j][column] > arr[j+1][column]) {
  for (int k = 0; k < 10; k++) {
  double temp = arr[j][k];
  arr[j][k] = arr[j+1][k];
  arr[j+1][k] = temp;
}
// Descending Order
} else if (!order && arr[j][column] < arr[j+1][column]) {
  if (arr[j][column] < arr[j+1][column]) {
  for (int k = 0; k < 10; k++) {
  double temp = arr[j][k];
  arr[j][k] = arr[j+1][k];
  arr[j+1][k] = temp;
  }
  }
}
}
}
}  // EndofSortByColumn


void SortByRow(double arr[][10], int rows, int sortRow, bool order) {
for (int column = 0; column < 10; column++) {
for (int i = 0; i < 10-column-1; i++) {
// Ascending
if (order && arr[sortRow][i] > arr[sortRow][i+1]) {
  for (int j = 0; j < rows; j++) {
  double temp = arr[j][i];
  arr[j][i] = arr[j][i+1];
  arr[j][i+1] = temp;
}
// Descending
} else if (!order && arr[sortRow][i] < arr[sortRow][i+1]) {
  for (int j = 0; j < rows; j++) {
  double temp = arr[j][i];
  arr[j][i] = arr[j][i+1];
  arr[j][i+1] = temp;
}
}
}
}
}  // End

double MedianInCol(double arr[][10], int rows, int column) {
// Taking in row and storing it
double tempArr[10];
for (int i = 0; i < rows; i++) {
  tempArr[i] = arr[i][column];
}
// Sorting data
for (int j = 0; j < rows-1; j++) {
  for (int i = 0; i < rows - j - 1; i++) {
  if (tempArr[i] > tempArr[i+1]) {
  double temp = tempArr[i];
  tempArr[i] = tempArr[i+1];
  tempArr[i+1] = temp;
}
}
}
// Checking for even or odd groups of data
if (rows % 2 == 0) {
  return (tempArr[rows / 2 - 1] + tempArr[rows / 2]) / 2.0;
} else {return tempArr[rows / 2];}
}  // End

int ModeInCol(double arr[][10], int rows, int column, double arr2[2]) {
  double tempArr[10];
  int occurance[10] = {0};
  int distinctValues = 0;
for (int i = 0; i < rows; i++) {
  bool found = false;
for (int j = 0; j < distinctValues; j++) {
  if (tempArr[j] == arr[i][column]) {
  occurance[j]++;
  found = true;
  break;
}
}
  if (!found) {
  tempArr[distinctValues] = arr[i][column];
  occurance[distinctValues] = 1;
  distinctValues++;
}
}

  int maxFrequency = 0;
  for (int i = 0; i < distinctValues; i++) {
  if (occurance[i] > maxFrequency) {
  maxFrequency = occurance[i];
}
}
int modeCount = 0;
for (int i = 0; i < distinctValues; i++) {
if (occurance[i] == maxFrequency) {
if (modeCount < 2) {
  arr2[modeCount] = tempArr[i];
}
modeCount++;
}
}
if (modeCount > 2) {
  arr2[0] = arr2[1]=-1;
  return 0;
}
  return modeCount;
}



