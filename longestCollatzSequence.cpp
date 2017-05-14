#include <iostream>

using namespace std;

long long int evenCollatz(long long int a){
	return a/2;
}

long long int oddCollatz(long long int a){
	return ((3 * a)+1);
}

long long int collatz(long long int a){
	if(a%2 == 0)
		return evenCollatz(a);
	return oddCollatz(a);
}

int main(){
	long long int max = 0;
	long long int maxCollatz = 2;
	for(int i = 500000; i < 1000000; i++){
		long long int collat = i;
		long long int count = 0;
		while(collat != 1){
			collat = collatz(collat);
			count++;
		}
		if(count > max){
			max = count;
			maxCollatz = i;
			cout << max << endl;
		}
		cout << i << endl; 
	}
	cout << maxCollatz;
}