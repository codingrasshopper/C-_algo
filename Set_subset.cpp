#include<iostream>
#include<math.h>
using namespace std;

//program to get all subsets

void powerset(char* arr){

	for(int count=0; count < 8; count++){  // 8 as 2^3 will be number of elements

		for (int j=0; j <3; j++){
			if (count & (1 <<j)){
				cout<< arr[j];
			}
		
		}
		cout <<endl;
	}

}




int main(){
	char arr[] = {'a', 'b', 'c'};
	int count, i;

	powerset(arr);


	return 0;
}