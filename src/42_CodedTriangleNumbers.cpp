#include <iostream> 
#include <vector>
#include <fstream>

using namespace std;

vector<string> words;
vector<int> triangleNumbers;

void getNextTriangleNumber(){
	triangleNumbers.push_back(triangleNumbers.at(triangleNumbers.size()-1) + triangleNumbers.size() + 1);
}

int main(){
	int numTriangleWords = 0;
	triangleNumbers.push_back(1);
	ifstream file;
	file.open("../input/words.txt");
	string temp;
	while(getline(file, temp, ',')){
		words.push_back(temp.substr(1,temp.length()-2));
	}
	for(int i = 0; i < words.size(); i++){
		int temp = 0;
		for(int j = 0; j < words.at(i).length(); j++){
			temp += (words[i][j] - 64);
		}
		while(temp > triangleNumbers.at(triangleNumbers.size() - 1))
			getNextTriangleNumber();
		for(int j = 0;j < triangleNumbers.size(); j++){
			if(temp == triangleNumbers.at(j)){
				numTriangleWords++;
				break;
			}
		}
	}
	cout << numTriangleWords;
}