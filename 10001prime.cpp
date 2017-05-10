#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;

void findNextPrime(int nextPrime){
	nextPrime++;
	bool prime = true;
	for(int i = 0; i < primes.size(); i++){
		if((nextPrime % primes.at(i)) == 0){
			prime = false;
			break;
		}
	}
	if(prime){
		primes.push_back(nextPrime);
		return;
	}
	findNextPrime(nextPrime);
}

int main(){
	primes.push_back(2);
	for(int i = 0; i < 10001; i++){
		findNextPrime(primes.at(i));
	}
	cout << primes.at(10000);
}