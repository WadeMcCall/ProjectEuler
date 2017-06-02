#include <iostream>
#include <vector>

using namespace std;

vector<long long int> primes;

void findNextPrime(int nextPrime){
	while(1){
		if(nextPrime!=2)
			nextPrime++;
		nextPrime++;
		bool prime = true;
		for(int i = 0; i < primes.size(); i++){
			if(primes.at(i) * primes.at(i) > nextPrime)
				break;
			if((nextPrime % primes.at(i)) == 0){
				prime = false;
				break;
			}
		}
		if(prime){
			primes.push_back(nextPrime);
			return;
		}
	}
}

long long int primeFactor(long long int num){
	while(true){
		for(int i = 0; i < primes.size(); i++){
			if((num % primes.at(i)) == 0){
				return primes.at(i);
			}
		}
		findNextPrime(primes.at(primes.size()-1));
	}
}

int main(){
	long long int max = 0;
	long long int temp = 0;
	primes.push_back(2);
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