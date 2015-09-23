#include <iostream>
using namespace std;

int rangeBitwiseAnd(int m, int n){
	/*long sum = 0x7fffffff;
	
	for(int i=m; i<=n ; i++){
		sum = i & sum;
	}*/

	
	return ((n>m) ? (rangeBitwiseAnd(m/2, n/2)<<1 ) : m );

}