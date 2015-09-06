#include<iostream>
using namespace std;

int main46(){
	int n,i;
	int sum = 0;
	i=1;
	n = 4617;
	while ((n/(pow(5,i))) > 1){
		sum = sum + (n/(pow(5,i)));
		i++;
	}

	cout << sum;
	return 0;
}