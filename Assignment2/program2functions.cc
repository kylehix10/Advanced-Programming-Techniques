//Copyright 2024 KHIX
#include "program2functions.h"
#include<cmath>
#include <tuple>

bool LeapYear(int year){
	if(year%400==0)
		return true;
	else if(year%100==0)
		return false;
	else if(year%4==0)
		return true;
	else
		return false;
}

int LastDayOfMonth(int month, int year){
	if(month!=2){
		if(month>12 || month<1)
			return 0;
		else if(month==4||month==6||month==9||month==11){
		year=0;
		return 30;
		}
		else if (month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		year=0;
		return 31;
		}
	}
	else{
		if(year<=0){
			return 0;
		}
		else{
			bool isLeap= LeapYear(year);
			if(isLeap==true)
				return 29;
			else
				return 28;
		}
	}
}

bool ValidDate(int month, int day, int year){
	if(month>12 || month<1 || day>31 || day<1||year<0)
		return false;
	else if((month==2||month==4||month==6||month==9||month==11)&&day==31)
		return false;
	else if (month==2){
		if(day==30)
			return false;
		else if(day<=28)
			return true;
		else if(day=29){
			bool isLeap=LeapYear(year);
			if(isLeap==true)
				return true;
			else
				return false;

		}
		else
			return true;
	}
	else
		return true;
		
	
}

void NextDate(int &month, int &day, int &year){
	bool isValid = ValidDate(month, day, year);
	if(isValid==true){
		if((month==4||month==6||month==9||month==11)&&day==30){
			month++;
			day=1;
		}
		else if((month==1||month==3||month==5||month==7||month==8||month==10)&&day==31){
			month++;
			day=1;
		}
		else if(month==12){
			month=1;
			day=1;
			year++;
		}
		else if(month==2 && day==28){
			bool isLeap=LeapYear(year);
			if(isLeap==true){
				day++;
			}
			else{
				day=1;
				month++;
			}
		}
		else if(month==2 && day==29){
			month=3;
			day=1;
		}
		else{
			day++;
		}
	}
	else{
		return;
	
	}
}


void PreviousDate(int &month, int &day, int &year){
	bool isValid = ValidDate(month, day, year);
	if(isValid==true)
	{
		if((month==2||month==4||month==6||month==9||month==11)&&day==1){
			month--;
			day=31;
		}
		else if((month==5||month==7||month==8||month==10||month==12)&&day==1)
		{
			month--;
			day=30;
		}
		else if(month==1 && day==1){
			month=12;
			day=31;
			year--;
		}
		else if(month==3 && day ==1){
			bool isLeap=LeapYear(year);
			if(isLeap==true){
				month--;
				day=29;
			}
			else{
				month--;
				day=28;
			}
		}
		else
			day--;
	}
	else
		return;
	
}


//End

