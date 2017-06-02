#include <iostream>
#include <vector>

using namespace std;

int main(){
	long int sum = 1;
	int count = 1;
	for(int i = 1; i < 501; i++){
		for(int j = 0; j < 4; j++){
			count += (2 * i);
			sum+= count;
		}
	}
	cout << sum;
}