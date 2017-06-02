#include <iostream>
#include <cmath>
#include <string>
#include <chrono>

using namespace std;

int GetNumberOfDigits (unsigned int i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int main(){
	int product = 1;
	int nextNumDigits = 1;
	string constant = "";
	int currDigit;
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	for(int i = 1; i < 1000001; i++){
		if(constant.length() < 1000000)
			constant += to_string(i);
		currDigit = constant[i-1] - '0';
		if(nextNumDigits == GetNumberOfDigits(i)){
			product *= currDigit;
			nextNumDigits++;
		}
	}
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	chrono::duration<double> time_span = chrono::duration_cast<chrono::microseconds>(t2 - t1);

	std::cout << "It took me " << time_span.count() << " seconds.";
	std::cout << std::endl;
	cout << product;
}