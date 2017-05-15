//TODO::create a vector of results and refer to it. this should massively speed up the program

#include <iostream>
#include <vector>

using namespace std;

int numPaths(int a, int b){
	if(a == 21 || b == 21)
		return 1;
	return numPaths(a + 1, b) + numPaths(a, b+1);
}

int main(){
	cout << numPaths(18,18);
}