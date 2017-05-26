#include <iostream>
#include "../include/InfInt.h"

using namespace std;

int main(){
	InfInt input;
	cout << "N = ";
	cin >> input;
	InfInt firstSlopeDenominator = input.intSqrt();
	bool found = false;
	InfInt two = 2;
	InfInt sum;
	InfInt firstSlopeDenominatorCopy;
	while(!found){
		sum = 0;
		firstSlopeDenominatorCopy = firstSlopeDenominator;
		while(firstSlopeDenominatorCopy > 0){
			sum+= firstSlopeDenominatorCopy;
			firstSlopeDenominatorCopy--;
		}
		if(sum >= (input - firstSlopeDenominator)){
			found = true;
			cout << "sum: " << sum << endl;
			cout << "firstSlopeDenominator: " << firstSlopeDenominator << endl;
		}
		else 
			firstSlopeDenominator++;
	}
	InfInt x = 0;
	InfInt y = 0;
	InfInt slopeNumerator = 1;
	InfInt count = 1;
	while(x <= input && y <= input){
		x += firstSlopeDenominator;
		y += slopeNumerator;
		if(firstSlopeDenominator != 1){
			firstSlopeDenominator--;
		}
		else
			slopeNumerator++;
		if(x <= input && y <= input)
			count++;
	}
	cout << count;
}