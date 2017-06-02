#include <iostream>
#include <vector>
#include "include/InfInt.h"

using namespace std;

vector<InfInt> results;

//brute force works nicely

int main(){
	InfInt result = 1;
	for(InfInt i = 2; i < 101; i++){
		for(InfInt j = 2; j < 101; j++){
			result = i;
			for(InfInt k = 1; k < j; k++){
				result *= i;
			}
			bool match = false;
			for(int k = 0; k < results.size(); k++){
				if(results[k] == result)
					match = true;
			}
			if(!match){
				results.push_back(result);
			}
		}
	}
	cout << results.size();
}