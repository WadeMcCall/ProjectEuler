#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long int> primeNums;

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
	bool prime = false;
	for(int i = 0; i < primeNums.size(); i++){
		if(n == primeNums.at(i))
			prime = true;
	}
	return prime;
}

int main(){
	primeNums.push_back(2);
	int max = 0;
	int a, b;
	for(int i = -999; i < 1000; i++){
		for(int j = -1000; j < 1001; j++){
			bool looking = true;
			int n = 0;
			while(looking){
				int result = (n*n) + (i*n) + j;
				if(result < 2)
					looking = false;
				else{
					looking = isPrime(result);
				}
				if(looking)
					n++;
			}
			if(n > max){
				max = n;
				cout << max << endl;
				a = i;
				b = j;
			}
		}
	}
	cout << "\nFINAL ANSWER: " << a*b;
}