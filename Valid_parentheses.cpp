#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
	stack<char> mystack;
	int i=0;
	if ( s.length() %2 != 0) return false;

	for(i=0; i< s.length(); i++){
		if ((s[i] == '(' ) || (s[i] == '{' ) || (s[i] == '[' )) {
				mystack.push(s[i]);
		}
		if ( s[i] == ')' ) {
			 if (mystack.empty()) return false;
			 if (mystack.top() == '(')
				 mystack.pop();
			 else return false;
		}
		if ( s[i] == '}' ) {
			if (mystack.empty()) {
				 cout<< "stack empty";
				 return false;}
			 if (mystack.top() == '{')
				 mystack.pop();
			 else return false;
		}
		if ( s[i] == ']' ) {
			if (mystack.empty()) {
				 cout<< "stack empty";
				 return false;}
			 if (mystack.top() == '[')
				 mystack.pop();
			 else return false;
		}
	}

	if (!mystack.empty()) return false;
	return true;
}