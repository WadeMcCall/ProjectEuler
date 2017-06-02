#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9};

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
	long long int max = 0;
	string result = "";
	for(int i = 1; i < 100000; i++){
		for(int j = 1; j < 10; j++){
			if(result.size() >= 9)
				break;
			result += to_string(i * j);
		}
		int res = stoll(result);
		if(isPandigital(res)){
			if(result.size() == 9){
				if(res > max){
					max = res;
				}
			}
		}
		result = "";
	}
	cout << max;
}