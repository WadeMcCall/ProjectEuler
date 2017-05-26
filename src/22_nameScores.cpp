#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

vector<string> names;

int main(){
	ifstream file;
	file.open("../input/names.txt");
	string temp;
	while(getline(file, temp, ',')){
		names.push_back(temp.substr(1,temp.length()-2));
	}
	sort(names.begin(), names.end());
	long long unsigned int sum = 0;
	for (int i = 0; i < names.size(); i++){
		int currentScore;
		for(int j = 0; j < names.at(i).length(); j++){
			currentScore += names.at(i)[j] - 64;
		}
		cout << currentScore << endl;
		sum += currentScore * (i+1);
		currentScore = 0;
	}
	cout << sum;
}