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
	int count = 0;
	long long int sum = 2;
	while(primes.at(count) < 2000000){
		findNextPrime(primes.at(count));
		count++;
		if(primes.at(count) < 2000000)
			sum += primes.at(count);
	}
	cout << sum;
}