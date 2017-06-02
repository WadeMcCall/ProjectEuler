#include <iostream>
#include "include/InfInt.h"

using namespace std;

InfInt Fib2 = 1;
InfInt Fib1 = 1;
InfInt currentFib = 2;
InfInt FibIndex = 3;

int main(){
	InfInt tempFib;
	while(currentFib.numberOfDigits() < 1000){
		tempFib = currentFib;
		currentFib += Fib1;
		Fib1 = tempFib;
		FibIndex++;
	}
	cout << FibIndex;
}