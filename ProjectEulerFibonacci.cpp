#include <iostream>

using namespace std;

int main(){
	int a = 1;
	int b = 2;
	int c, sum = 0;
	while(b < 4000000){
		if(b % 2 == 0){
			sum += b;
		}
		c = a + b;
		a = b;
		b = c;
	}
	cout << sum;
}