//gross unreadable code
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> abundantNumbers;
vector<int> sumOfAbundantNumbersList;

int d(int n){
	int sum = 0;
	for(int i = 1; i < (n/2) +1; i++){
		if(n%i == 0)
			sum += i;
	}
	return sum;
}

int main(){
	for(int i = 12; i < 28111; i++){
		if(d(i) > i)
			abundantNumbers.push_back(i);
	}
	for(int i = 0; i < abundantNumbers.size(); i++){
		for(int j = i; j < abundantNumbers.size(); j++){
			sumOfAbundantNumbersList.push_back(abundantNumbers[i] + abundantNumbers[j]);
		}
	}
	cout << sumOfAbundantNumbersList.size() << endl;
	int sum = 0;
	for(int i = 1; i < 24; i++){
		sum += i;
	}
	sort(sumOfAbundantNumbersList.begin(), sumOfAbundantNumbersList.end());
	int prevj = 0;
	for(int i = 24; i < 28124; i++){
		bool match = false;
		for(int j = prevj; sumOfAbundantNumbersList.at(j) <= i; j++){
			if(i == sumOfAbundantNumbersList.at(j)){
				prevj = j;
				match = true;
				break;
			}
		}
		if(!match)
			sum+=i;
	}
	cout << sum;
}