#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isPalindrome(int x){
	stringstream ss;
	ss << x;
	string stringX = ss.str();
	while(stringX.length() > 1){
		char lastDigit = stringX.at(stringX.length()-1);
		char firstDigit = stringX.at(0);
		if(lastDigit != firstDigit)
			return false;
		else stringX = stringX.substr(1, stringX.length() - 2);
	}
	return true;
}

int main(){
	int max = 0;
	for(int i = 500; i <= 999; i++){
		for(int j = 500; j < 999; j++){
			if(isPalindrome(i*j)){
				if((i*j) > max){
					max = i*j;
				}
			}
		}
	}
	cout << max << endl;
}