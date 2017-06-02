#include <iostream>
#include <vector>

using namespace std;

vector<int> factorials;

int factorial(int n){
	if(n > 1)
		return n * factorial(n-1);
	return n;
}

int main(){
	for(int i = 0; i < 10; i++){
		factorials.push_back(factorial(i));
	}
	factorials[0] = 1;
	int count = 1;
	int sum = factorials[9];
	int other = 9;
	while(other < sum){					//find the range in which solutions could occur
		sum += factorials[9];
		other *=10;
		other +=9;
	}
	int result = 0;
	for(int i = 3; i < other; i++){		
		int temp = i;
		int sum1 = 0;
		while(temp > 0){
			sum1+=factorials[(temp%10)];
			temp = temp /10;
		}
		if(sum1 == i){
			result += sum1;
		}
	}
	cout << result;
}