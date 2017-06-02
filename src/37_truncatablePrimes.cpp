#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<long long int> primeNums;

int GetNumberOfDigits (unsigned int i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

void findNextPrime(int nextPrime){
	while(1){
		if(nextPrime!=2)
			nextPrime++;
		nextPrime++;
		bool prime = true;
		for(int i = 0; i < primeNums.size(); i++){
			if(primeNums.at(i) * primeNums.at(i) > nextPrime)
				break;
			if((nextPrime % primeNums.at(i)) == 0){
				prime = false;
				break;
			}
		}
		if(prime){
			primeNums.push_back(nextPrime);
			return;
		}
	}
}

bool isPrime(int n){
	while(n > primeNums.at(primeNums.size()-1)){
		findNextPrime(primeNums.at(primeNums.size()-1));
	}
	return binary_search (primeNums.begin(), primeNums.end(), n);
}

bool isTruncatablePrime(int n){
	int temp = n;
	while(n > 0){
		if(!isPrime(n))
			return false;
		n = n/10;
	}
	while(temp > 0){
		if(!isPrime(temp))
			return false;
		int mod = 1;
		for(int i = 1; i < GetNumberOfDigits(temp); i++){
			mod *= 10;
		}
		temp = temp % mod;
	}
	return true;
}

int main(){
	primeNums.push_back(2);
	int numTruncPrimes = 0;
	int sum = 0;
	int count = 11;
	while(numTruncPrimes < 11){
		if(isTruncatablePrime(count)){
			sum += count;
			numTruncPrimes++;
		}
		count+=2;
	}
	cout << sum;
}