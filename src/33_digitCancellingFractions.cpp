//this program simply gives you the fractions in question. i used a calculator to find their lcd.
#include <iostream>
#include <vector>

using namespace std;

int main(){
	for(int i = 10; i < 100; i++){
		for(int j = i+1; j < 100; j++){
			if(i%10 || j%10){
				vector<int> digitsI;
				vector<int> digitsJ;
				int tempi = i;
				int tempj = j;
				int temp;
				while(tempi > 0){
					temp = tempi % 10;
					digitsI.push_back(temp);
					tempi = tempi/10;
				}
				while(tempj > 0){
					temp = tempj % 10;
					digitsJ.push_back(temp);
					tempj = tempj/10;
				}
				double ratio = ((double)i)/((double)j);
				if(digitsI[0] == digitsJ[0]){
					if(ratio == (double)digitsI[1]/(double)digitsJ[1]){
						cout << i << "/" << j << endl;
					}
				}
				if(digitsI[1] == digitsJ[0]){
					if(ratio == (double)digitsI[0]/(double)digitsJ[1]){
						cout << i << "/" << j << endl;
					}
				}
				if(digitsI[0] == digitsJ[1]){
					if(ratio == (double)digitsI[1]/(double)digitsJ[0]){
						cout << i << "/" << j << endl;
					}
				}
				if(digitsI[1] == digitsJ[1]){
					if(ratio == (double)digitsI[0]/(double)digitsJ[0]){
						cout << i << "/" << j << endl;
					}
				}
			}
		}
	}
}