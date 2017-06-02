//find congruency in large mods

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

vector<long long int> results;

int main(){
	ifstream file;
	file.open("log.txt");
	long int temp;
	while(file >> temp){
		results.push_back(temp);
	}
	cout << "done filling vector" << endl;
	for(int i = 0; i < results.size(); i++){
		for(int j = i+1; j < results.size(); j++){
			if(results[i] == results[j]){
				cout << results[i] << " : " << results[i+1] << endl;
				if(results[i+1] == results[j+1]){
					cout << "found!! " << i << ": " << j << ": " << results.at(i) << endl;
					i = results.size();
				}
			}
		}
	}
}