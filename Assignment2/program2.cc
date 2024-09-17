//Copyright 2024
//Kyle Hix
#include<iostream> 
using std::cout;
using std::cin;
using std::endl;
#include "program2functions.h"

int main(){
	
	int month, day, year, month2, day2, year2;
	char slash1, slash2;
	
	//Inputing data
	cin>>month>>slash1>>day>>slash2>>year>>month2>>slash1>>day2>>slash2>>year2;

	//Checking ValidDate
	bool isValid1= ValidDate(month, day, year);
	bool isValid2= ValidDate(month2, day2, year2);
	if(isValid1==false){
		cout<<month<<slash1<<day<<slash2<<year<<" is not a valid date"<<endl;
		exit(0);
	}
	else if(isValid2==false){
		cout<<month2<<slash1<<day2<<slash2<<year2<<" is not a valid date"<<endl;
		exit(0);
	}
	
	//Checking order of dates
	bool secondAhead=false;
	if(year < year2 || (year == year2 && month < month2) || (year == year2 && month == month2 && day < day2)||(year==year2 && month==month2 && day==day2))
		secondAhead=true;
	
	//Counting Days
	int dayCounter=0;
	
	
	if(secondAhead==true){
		int oMonth=month2;
		int oDay=day2;
		int oYear=year2;
		while(year!=year2 || month!=month2 || day!=day2){
			PreviousDate(month2, day2, year2);
			dayCounter++;
		}
		cout<<month<<slash1<<day<<slash2<<year<<" is "<<dayCounter<<" days before "<<oMonth<<slash1<<oDay<<slash2<<oYear<<endl;
	}
	
	else{
		int oMonth=month;
		int oDay=day;
		int oYear=year;
		while(year!=year2 || month!=month2 || day!=day2){
				PreviousDate(month, day, year);
				dayCounter++;
			}
			cout<<oMonth<<slash1<<oDay<<slash2<<oYear<<" is "<<dayCounter<<" days after "<<month2<<slash1<<day2<<slash2<<year2<<endl;
	}

	return 0;
}
