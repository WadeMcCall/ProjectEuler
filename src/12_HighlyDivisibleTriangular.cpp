#include<iostream>

using namespace std;

int findNumFactors(int a){
	int count = 0;
	int numToCheck = 1;
	while(1){
		if(numToCheck*numToCheck > a)
			return count*2;
		if(a%numToCheck == 0)
			count++;
		numToCheck++;
	}
}

int main(){
	long long unsigned int currentTriangularNumber = 1;
	long long unsigned int triangleNumberCount = 1;
	while(1){
		triangleNumberCount++;
		currentTriangularNumber += triangleNumberCount;
		int a = findNumFactors(currentTriangularNumber);
		if(a > 500){
			cout << currentTriangularNumber << endl;
			return 0;
		}
	}
}