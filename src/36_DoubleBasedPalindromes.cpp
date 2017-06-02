#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

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

string to_bin(unsigned int value) {
  if (value == 0) return "0";
  string result;
  while (value != 0) {
    result += '0' + (value & 1);
    value >>= 1;
  }
  reverse(result.begin(), result.end());
  return result;
}

bool isBaseTwoPalindrome(int x){
	string value = to_bin(x);
	while(value.length() > 1){
		char lastDigit = value.at(value.length()-1);
		char firstDigit = value.at(0);
		if(lastDigit != firstDigit)
			return false;
		else value = value.substr(1, value.length() - 2);
	}
	return true;
	
}

int main(){
	int sum = 0;
	for(int i = 0; i < 1000000; i++){
		if(isPalindrome(i) && isBaseTwoPalindrome(i))
			sum+=i;
	}
	cout << sum;
}