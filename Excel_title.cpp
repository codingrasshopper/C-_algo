#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	string str;
	int j;
	int base=1, dec =0, rem = 0;

	cin>>str;
	reverse(str.begin(),str.end());
	cout << str;

	for ( int i=0; i<str.length(); i++) {
		cout << "i, str[i]" << i, str[i] ;
		cout <<endl;
		cout << "each char is " << str[i] -'A'+1;
		rem += (str[i] -'A'+1 ) *(pow(26,i));
		cout << "rem is " << rem;
	}

	cout << "value" << rem;
}