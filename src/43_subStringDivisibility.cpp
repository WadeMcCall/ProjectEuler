#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_permutation(vector<long int> &array) {
    // Find non-increasing suffix
    if (array.size() == 0)
        return false;
    vector<long int>::iterator i = array.end() - 1;
    while (i > array.begin() && *(i - 1) >= *i)
        --i;
    if (i == array.begin())
        return false;

    // Find successor to pivot
    vector<long int>::iterator j = array.end() - 1;
    while (*j <= *(i - 1))
        --j;
    iter_swap(i - 1, j);

    // Reverse suffix
    reverse(i, array.end());
    return true;
}

bool isSubStringDivisible(vector<long int> &array){
	long int temp = 0;
	temp += array[1];
	temp*=10;
	temp+= array[2];
	temp*= 10;
	temp += array[3];
	if(temp % 2)
		return false;
	temp *= 10;
	temp += array[4];
	temp %= 1000;
	if(temp % 3)
		return false;
	temp *= 10;
	temp += array[5];
	temp %= 1000;
	if(temp % 5)
		return false;
	temp *= 10;
	temp += array[6];
	temp %= 1000;
	if(temp % 7)
		return false;	
	temp *= 10;
	temp += array[7];
	temp %= 1000;
	if(temp % 11)
		return false;
	temp *= 10;
	temp += array[8];
	temp %= 1000;
	if(temp % 13)
		return false;
	temp *= 10;
	temp += array[9];
	temp %= 1000;
	if(temp % 17)
		return false;
	return true;
}

int main(){
	vector<long int> permutations {0,1,2,3,4,5,6,7,8,9};
	long long int sum = 0;
	while(next_permutation(permutations)){
		long unsigned int temp = 0;
		if(isSubStringDivisible(permutations)){
			for(int i = 0; i < permutations.size(); i++){
				temp+=permutations[i];
				if(i < permutations.size()-1)
					temp *= 10;
			}
			sum += temp;
		}
	}
	cout << sum;
}