#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers {1, 2, 3, 4, 5, 6, 7};
vector<bool> primeNums(10000000, 1);

void seiveOfEratasthones(){
	primeNums[0] = false;
	primeNums[1] = false;
	for(int i = 2; i < primeNums.size(); i++){
		for(int j = i*2; j < primeNums.size(); j+=i){
			if(!primeNums[i])
				break;
			if(j<10000000){
				primeNums[j] = false;
			}
		}
	}
}

bool isPandigital(int a){
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
	if(temp.size() == 0)
		return true;
	return false;
}

int main(){
	seiveOfEratasthones();
	cout << "found primes" << endl;
	int primePan = 1;
	for(int i = 9999999; i > 0; i--){
		//cout << i << endl;
		if(primeNums[i] && isPandigital(i)){
			primePan = i;
			break;
		}
	}
	cout << primePan;
}