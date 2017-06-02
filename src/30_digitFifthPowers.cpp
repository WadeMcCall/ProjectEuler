#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	vector<int> powers;
	for(int i = 1; i < 10; i++){
		powers.push_back((int)pow(i,5));
	}
	int sum =0;
	for(int i = 2; i < 10000000; i++){  //just assuming no number over 10 million works since the powers of 4 examples were all low in comparison
		int temp = i;
		int currDigit = 0;
		int tempSum = 0;
		while(temp > 0){
			currDigit = temp % 10;
			temp = temp/10;
			if(currDigit != 0)
				tempSum += powers[currDigit-1];
		}
		if(tempSum == i)
			sum += tempSum;
	}
	cout << sum;
}