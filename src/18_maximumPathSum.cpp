//brute force

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> sumTriangle;	

int max(int a, int b){
	return (a >= b ? a : b);
}

int findMaxSum(int i, int j){
	if(i == sumTriangle.size() -2)
		return sumTriangle.at(i).at(j) + max(sumTriangle.at(i+1).at(j), sumTriangle.at(i+1).at(j+1));
	return sumTriangle.at(i).at(j) + max(findMaxSum(i+1,j), findMaxSum(i+1,j+1));
}	

int main(){
	fstream infile;
	infile.open("../input/maximumPaths.txt");	//file with our triangle values in it
	string temp;
	while(getline(infile, temp)){
		vector<int> tempVect;				
		stringstream ss(temp);
		string s;
		while(getline(ss, s, ' ')){			//while there is another number in the line from the file in our stringstream
			tempVect.push_back(stoi(s));
		}
		sumTriangle.push_back(tempVect);	//vector shenanigans
		tempVect.clear();
	}
	int sum = findMaxSum(0,0);
	cout << sum;
}