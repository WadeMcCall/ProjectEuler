#include <iostream>
#include <cmath>
#include <string>
#include "include/InfInt.h"

using namespace std;

InfInt divisibilityStreak(InfInt n){
	if(n%2 == 0)
		return 1;
	InfInt count = 1;
	while(1){
		n++;
		count++;
		if(n%count != 0){
			return count-1;
		}
	}
}

InfInt p(InfInt s, InfInt N){
	InfInt count = 0;
	for(InfInt i = 3; i < N; i+=2){
		if(s == divisibilityStreak(i))
			count++;
	}
	return count;
}

int main(){
	InfInt sum = 0;
	for(int i = 3; i < 10000; i+=2){
		InfInt result;
		string power = to_string(pow(4,i));
		string token = power.substr(0, power.find("."));
		result = token;
		sum = divisibilityStreak((InfInt) i);
		cout << sum << ": " << i << endl;
	}
	sum = p(6, 1000000);
	cout << sum;
}