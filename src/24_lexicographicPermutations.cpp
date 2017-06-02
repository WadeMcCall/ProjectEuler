#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//-std=c++11
vector<int> permutation = {0,1,2,3,4,5,6,7,8,9};

int main(){
	int count = 1;
	int k, l;
	while(count < 1000000){
		for(int i = 8; i >= 0; i--){
			if(permutation[i] < permutation[i+1]){
				k = i;
				i = 0;
				for(int j = 9; j >= k; j--){
					if(permutation[k] < permutation[j]){
						l = j;
						j = 0;
					}
				}
			}
		}
		iter_swap(permutation.begin() + k, permutation.begin() + l);
		reverse(permutation.begin() + k + 1, permutation.end());
		count ++;
	}
	for(int i = 0; i < permutation.size(); i++){
		cout << permutation.at(i);
	}
}