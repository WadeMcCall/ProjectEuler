#include <iostream>
#include <vector>

using namespace std;

//c++11
vector<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9};

vector<int> d(int n){
	vector<int> factors;
	for(int i = 2; i < (n/2) +1; i++){
		if(n%i == 0)
			factors.push_back(i);
	}
	return factors;
}

bool isPandigital(int a, int b, int p){
	vector<int> temp = numbers;
	while(a > 0){
		int c = a % 10;
		a = a/10;
		bool found = false;
		for(int i = 0; i < temp.size(); i++){
			if(c == temp[i]){
				temp.erase(temp.begin()+i);
				found = true;
				break;
			}
		}
		if(!found)
			return false;
	}	
	while(b > 0){
		int c = b % 10;
		b = b/10;
		bool found = false;
		for(int i = 0; i < temp.size(); i++){
			if(c == temp[i]){
				temp.erase(temp.begin()+i);
				found = true;
				break;
			}
		}
		if(!found)
			return false;
	}
	while(p > 0){
		int c = p % 10;
		p = p/10;
		bool found = false;
		for(int i = 0; i < temp.size(); i++){
			if(c == temp[i]){
				temp.erase(temp.begin()+i);
				found = true;
				break;
			}
		}
		if(!found)
			return false;
	}
	if(temp.size() == 0)
		return true;
	return false;
}

int main(){
	vector<int> factors;
	int sum = 0;
	for(int i = 3; i < 10000; i++){
		factors = d(i);
		for(int j = 0; j < factors.size()/2; j++){
			if(isPandigital(factors[j], factors.at(factors.size()-(j+1)), i)){
				sum += i;
				break;
			}
		}
	}
	cout << sum;
}