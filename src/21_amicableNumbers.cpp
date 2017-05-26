#include <iostream>

using namespace std;

int d(int n){
	int sum = 0;
	for(int i = 1; i < (n/2) +1; i++){
		if(n%i == 0)
			sum += i;
	}	
	return sum;
}

bool isAmicable(int i, int j){
	if(i==j)
		return false;
	int b = d(j);
	if(b == i)
		return true;
	return false;
}

int main(){
	int sum = 0;
	for(int i = 2; i < 10000; i++){
		if(isAmicable(i,d(i))){
			sum += i;
		}
	}
	cout << sum;
}