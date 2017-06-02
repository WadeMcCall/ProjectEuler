#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;

vector<long long int> primeNums;

int numDigits(int number)
{
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
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

bool isCircularPrime(int n){
	vector<int> digits;
	while(n > 0){
		digits.push_back(n%10);
		n = n/10;
	}
	for(int j = 0; j < digits.size(); j++){
		int temp = 0;
		for(int i = 0; i < digits.size(); i++){
			temp += digits[i];
			if(i < digits.size() -1)
				temp*= 10;
		}
		if(!isPrime(temp)){
			return false;
		}
		rotate(digits.begin(), digits.begin() + 1, digits.end());
	}
	return true;
}

int main(){
	primeNums.push_back(2);
	primeNums.push_back(3);
	int count = 0;
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	for(int i = 2; i < 1000000; i++){
		if(isCircularPrime(i))
			count++;
	}
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::microseconds>(t2 - t1);

	std::cout << "It took me " << time_span.count() << " seconds.";
	std::cout << std::endl;
	cout << count;
}