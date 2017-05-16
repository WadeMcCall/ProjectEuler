#include <iostream>
#include <vector>

using namespace std;

vector<int> letterCount;

int generateStringLength(int a){
	if(a < 21)
		return letterCount.at(a);
	if(a < 100){
		int offset = a / 10;
		return letterCount.at(18+offset) + letterCount.at(a%10);
	}
	if(a < 1000){
		int numHundred = a / 100;
		int ret = letterCount.at(numHundred) + 7;  //size of "x hundred";
		if(a%100)
			return ret + 3 + generateStringLength(a%100);  //size of "x hundred" + "and" + tens and ones place string
		return ret;
	}
	else return 11; //size of "one thousand"
}

int main(){
	letterCount.push_back(0); //zero is 0 because you never say "zero"
	letterCount.push_back(3); //one
	letterCount.push_back(3); //two
	letterCount.push_back(5); //three
	letterCount.push_back(4); //four
	letterCount.push_back(4); //five
	letterCount.push_back(3); //six
	letterCount.push_back(5); //seven
	letterCount.push_back(5); //eight
	letterCount.push_back(4); //nine
	letterCount.push_back(3); //ten
	letterCount.push_back(6); //eleven
	letterCount.push_back(6); //twelve
	letterCount.push_back(8); //thirteen
	letterCount.push_back(8); //fourteen
	letterCount.push_back(7); //fifteen
	letterCount.push_back(7); //sixteen
	letterCount.push_back(9); //seventeen
	letterCount.push_back(8); //eighteen
	letterCount.push_back(8); //nineteen
	letterCount.push_back(6); //twenty
	letterCount.push_back(6); //thirty(21)
	letterCount.push_back(5); //forty (22)
	letterCount.push_back(5); //fifty (23)
	letterCount.push_back(5); //sixty (24)
	letterCount.push_back(7); //seventy (25)
	letterCount.push_back(6); //eighty (26)
	letterCount.push_back(6); //ninety (27)
	
	int sum = 0;
	for(int i = 1; i < 1001; i++){
		int s = generateStringLength(i);
		sum += s;
	}
	cout << sum;
}