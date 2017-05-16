#include "infint/infint.h"

using namespace std;

int main(){
	InfInt result = 1;
	for(int i = 0; i < 1000; i++){
		result *= 2;
	}
	int ret = 0;
	for(int i = 0; i < result.numberOfDigits(); i++){
		ret += result.digitAt(i);
	}
	cout << ret;
}