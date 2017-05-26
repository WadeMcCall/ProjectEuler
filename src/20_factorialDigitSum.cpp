#include <iostream>
#include "include/InfInt.h"

using namespace std;

int main(){
	InfInt product = 1;
	for(int i = 1; i < 101; i++){
		product *= i;
	}
	InfInt sum = 0;
	for (int i = 0; i < product.numberOfDigits(); i++){
		sum += product.digitAt(i);
	}
	cout << sum;
}