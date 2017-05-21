//dynamic programming

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> sumTriangle;
vector<vector<int>> length_to;	

int longestPath(){													//our triangle graph is already in a topological sort
	for(int i = 0; i < length_to.size() -1; i++){
		for(int j = 0; j < i+1; j++){
			if(length_to.at(i+1).at(j) <= (length_to.at(i).at(j) + sumTriangle.at(i+1).at(j))){
				length_to.at(i+1).at(j) = (length_to.at(i).at(j) + sumTriangle.at(i+1).at(j));
			}
			if(length_to.at(i+1).at(j+1) <= (length_to.at(i).at(j) + sumTriangle.at(i+1).at(j+1))){
				length_to.at(i+1).at(j+1) = (length_to.at(i).at(j) + sumTriangle.at(i+1).at(j+1));
			}
		}
	}
	int maxSum = 0;
	for(int j = 0; j < length_to.at(length_to.size()-1).size()-1; j++){
		if(maxSum < length_to.at(length_to.size()-1).at(j))
			maxSum = length_to.at(length_to.size()-1).at(j);
	}
	return maxSum;
}	

int main(){
	fstream infile;
	infile.open("../input/triangle.txt");	//file with our triangle values in it
	string temp;
	while(getline(infile, temp)){
		vector<int> tempVect;				
		stringstream ss(temp);
		string s;
		while(getline(ss, s, ' ')){			//while there is another number in the line from the file in our stringstream
			tempVect.push_back(stoi(s));
		}
		length_to.push_back(tempVect);
		sumTriangle.push_back(tempVect);	//vector shenanigans
		tempVect.clear();
	}
	int sum = longestPath();
	cout << sum;
}