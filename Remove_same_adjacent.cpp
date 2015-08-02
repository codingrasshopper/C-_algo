#include <iostream>
using namespace std;
//Program to remove same characters in adjacent letters

int remove_adjacent(){
	char s[]= "aaabcccd";
	int store, i;

	store = 0;
	for(i=0; s[i] != '\0'; i++){
		if ( s[i+1] != s[i] ) {
			s[store+1] = s[i+1];
			store++ ;
		}
	}
	s[store+1] = '\0';

	cout << s;
		
	return 0;
}


