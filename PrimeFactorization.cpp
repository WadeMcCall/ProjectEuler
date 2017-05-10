#include <iostream>
#include <vector>

using namespace std;

vector<long long int> primeNums;

void findNextPrime(int nextPrime){
	nextPrime++;
	bool prime = true;
	for(int i = 0; i < primeNums.size(); i++){
		if((nextPrime % primeNums.at(i)) == 0){
			prime = false;
			break;
		}
	}
	if(prime){
		primeNums.push_back(nextPrime);
		return;
	}
	findNextPrime(nextPrime);
}

long long int primeFactor(long long int num){
	while(true){
		for(int i = 0; i < primeNums.size(); i++){
			if((num % primeNums.at(i)) == 0){
				return primeNums.at(i);
			}
		}
		findNextPrime(primeNums.at(primeNums.size()-1));
	}
}

int main(){
	long long int max = 0;
	long long int temp = 0;
	primeNums.push_back(2);
	long long int primeFactorNumber = 600851475143;
	while(primeFactorNumber != 1){
		temp = primeFactor(primeFactorNumber);
		if(temp > max)
			max = temp;
		primeFactorNumber = primeFactorNumber / temp;
		cout << primeFactorNumber<< endl;
	}
	cout << max;
}