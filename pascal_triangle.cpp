#include <iostream>
#include <vector>
using namespace std;


void pascal(int n){
	vector<int> res(n+1);
	res[0] = 1;
	for (int i=0; i<=n ; i++){
		for(int j=i; j>0 ; j--){
			res[j] = res[j] + res[j-1];
		}
	}

	for (int i=0; i< res.size(); i++)
		cout << res[i];
}

