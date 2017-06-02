#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int max = 0;
	vector<int> p(1000,0);
	for(int i = 1; i < 1000; i++){
		for(int j = 1; j < 1000; j++){
			double c = sqrt((double)((i*i) + (j*j)));
			double temp;
			if(modf(c, &temp) <= 0.0000001){
				if((c + i + j) < 1000){
					p[c+i+j] += 1;
				}
			}
		}
	}
	int bestP = 0;
	for(int i = 0; i < 1000; i++){
		if(p[i] > max){
			max = p[i];
			bestP = i;
		}
	}
	cout << bestP;
}