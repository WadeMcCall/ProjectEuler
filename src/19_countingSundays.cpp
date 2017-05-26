#include <iostream>

using namespace std;

int day = 1;
int month = 1;
int year = 1900;
//30 days 4, 6, 9, 11
//31 days 1, 3, 5, 7, 8, 10, 12
//february 2

int main(){
	int count = 0;	
	while(month <= 12){
		if(month == 4 || month == 6 || month == 9 || month == 11){
			day += 30;
		}
		else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
			day += 31;
		}
		else{
			if(year % 4 == 0 && year != 1900){
				day += 29;
			}
			else day+= 28;
		}
		day = day % 7;
		month++;
	}
	month = 1;
	year++;
	while(year < 2001){
		if(year == 1917)
			cout << day << endl;
		while(month <= 12){
			if(month == 4 || month == 6 || month == 9 || month == 11){
				day += 30;
			}
			else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
				day += 31;
			}
			else{
				if(year % 4 == 0){
					day += 29;
				}
				else day+= 28;
			}
			day = day % 7;
			if(day == 0)
				count++;
			month++;
		}
		month = 1;
		year++;
	}
	cout << count;
}