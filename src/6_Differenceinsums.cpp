#include <iostream>

using namespace std;

int sumofsquares(int max){
	int sum = 0;
	for(int i = 1; i <= max; i++){
		sum += i * i;
	}
	return sum;
}

int squareofsums(int max){
	int sum = 0;
	for(int i = 1; i <= max; i++){
		sum += i;
	}
	return (sum * sum);
}

int main(){
	cout << (squareofsums(100) - sumofsquares(100)) << endl;
}