//this gets answers that are correct but it will never be fast enough
//need to find a better way

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long unsigned int sideRectangles = 1;
long unsigned int topRectangles = 1;
long unsigned int prevSolution = 0;
int mod = ((int)pow(17,7));

long long int function(long long int n){
	long unsigned int sum = 4*prevSolution + (sideRectangles - 1) + (2*(topRectangles - 1));
	prevSolution = sum % mod;
	long unsigned int tempRectangles = sideRectangles;
	sideRectangles += 2 * topRectangles;
	sideRectangles = sideRectangles % mod;
	topRectangles = tempRectangles;
	return prevSolution;
}

int main(){
	long long unsigned int N;
	long unsigned int ret;
	cout << "N = ";
	cin >> N;
	for(long long int i = 0; i < N; i++){
		ret = function(i);
	}
	cout << "sideRectangles: " << sideRectangles << endl;
	cout << ret;
}