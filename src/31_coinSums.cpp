//this solution requires me to compile with increased stack size on my system
//g++ -Wl,--stack,10000000 -o pe 31_coinSums.cpp
//this is a very bad solution :(

#include <iostream>

using namespace std;

int findNextPermutation(int num200, int num100, int num50, int num20, int num10, int num5, int num2, int num1){
	if(num2 != 0){
		num2--;
		num1 += 2;
	}else if(num5 != 0){
		num5--;
		num1++;
		num2+=2;
		while(num1 >= 2){
			num2++;
			num1-=2;
		}
	}else if(num10 != 0){
		num10--;
		num5 +=2;
		while(num1 >= 5){
			num5++;
			num1 -= 5;
		}
	}else if(num20 != 0){
		num20--;
		num10 += 2;
		while(num1 >= 10){
			num10++;
			num1 -= 10;
		}
	}else if(num50 != 0){
		num50--;
		num20+=2;
		num1+=10;
		while(num1 >= 20){
			num20++;
			num1 -=20;
		}
		while(num1 >= 10){
			num10++;
			num1-=10;
		}
	}else if(num100 != 0){
		num100--;
		num50+=2;
		while(num1 >= 50){
			num50++;
			num1-=50;
		}
	}else if(num200 != 0){
		num200--;
		num100+=2;
	}else return 1;
	return 1 + findNextPermutation(num200, num100, num50, num20, num10, num5, num2, num1);
}

int main(){
	cout << findNextPermutation(1,0,0,0,0,0,0,0);
	
	//grumbal's working code.
	//same solution without recursion and is much cleaner
	//int count=0;
	//int m = 200;
    //int a, b, c, d, e, f, g;
    //for( a=m ; a>=0 ; a -= 200 )
    //for( b=a ; b>=0 ; b -= 100 )
    //for( c=b ; c>=0 ; c -= 50 )
    //for( d=c ; d>=0 ; d -= 20 )
    //for( e=d ; e>=0 ; e -= 10 )
    //for( f=e ; f>=0 ; f -= 5 )
    //for( g=f ; g>=0 ; g -= 2 )
    //    count++;
	//printf("ex31b: count=%d\n", count);
}