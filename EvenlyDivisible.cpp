#include <iostream>

using namespace std;

bool isEvenlyDivisible(int x){
	int arr[] = {2,3,5,7,11,13,17,19};
	bool even = true;
	for(int i = 0; i < 8; i++){
		if(x % arr[i] != 0){
			even = false;
			break;
		}
	}	
	return even;
}

int main(){
	int count = 2520;
	while(true){
		if(isEvenlyDivisible(count)){
			cout << count << endl;
			return 0;
		}
		count++;
	}
}