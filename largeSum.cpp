#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
	//read in the inputs from my input file
	ifstream inFile;
	inFile.open("largeSumInputFile.txt");
	vector<string> inputs;
	string temp;
	while(inFile >> temp ){
		inputs.push_back(temp);
	}
	vector<unsigned long long int> lessSignificantInputs;
	vector<unsigned long long int> middleSignificantInputs;
	vector<unsigned long long int> moreSignificantInputs;
	unsigned long long int tempint;
	for(int i = 0; i < inputs.size(); i++){
		temp = inputs.at(i).substr(0,16);
		tempint = stoll(temp);
		moreSignificantInputs.push_back(tempint);
		temp = inputs.at(i).substr(16,17);
		tempint = stoll(temp);
		middleSignificantInputs.push_back(tempint);
		temp = inputs.at(i).substr(33,25);
		tempint = stoll(temp);
		lessSignificantInputs.push_back(tempint);	
	}
	unsigned long long int sum = 0;
	for(int i = 0; i < lessSignificantInputs.size(); i++){
		sum += lessSignificantInputs.at(i);
	}
	sum = sum/10000000000000000;
	for(int i = 0; i < middleSignificantInputs.size(); i++){
		sum += middleSignificantInputs.at(i);
	}
	sum = sum/100000000000000000;
	for(int i = 0; i < moreSignificantInputs.size(); i++){
		sum += moreSignificantInputs.at(i);
	}
	cout << sum;
}