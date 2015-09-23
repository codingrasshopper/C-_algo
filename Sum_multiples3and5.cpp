#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main50() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
	int myint;
    cin >> T;
    vector<int> N;
    for (int i=0; i<T; i++){
		cout << "Enter";
		cin >> myint;
        N.push_back(myint);
    }
    /*int j=0;
    while (T>0){
        int sum=0;
        for (int i=0; i<N[j]; i++){
            if((i%3 == 0) || (i%5 == 0)){
                sum += i;
            }
            //else continue;
        }
        cout << sum << endl;
        T--;
        j++;
    }
	*/
	int i=0;
	while (T>0){
        int sum=0;
		
		sum = 3*int((N[i]-1)/3)*(1+int((N[i]-1)/3))/2 +
			5*int((N[i]-1)/5)*(1+int((N[i]-1)/5))/2 -
			15*int((N[i]-1)/15)*(1+int((N[i]-1)/15))/2;
		cout << sum << endl;
        T--;
		i++;
	}
		


    return 0;
}
