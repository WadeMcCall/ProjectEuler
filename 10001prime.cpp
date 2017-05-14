#include <iostream>
#include <vector>

using namespace std;

vector<long int> primes;

void findNextPrime(long int nextPrime){
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

int main(){
	primes.push_back(2);
	for(long int i = 0; i < 10001; i++){
		findNextPrime(primes.at(i));
	}
	cout << primes.at(10001);
}