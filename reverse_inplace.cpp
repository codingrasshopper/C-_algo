#include <iostream>
#include<string>
using namespace std;

void reverse(string& src, int start, int end){
	while (start < end) {
		char tmp = src[start];
		src[start] = src[end];
		src[end] = tmp;
		end--;
		start++;
	}
}

int main(){
	string src="p  Everything is awesome!! ";

	reverse(src, 0, src.length() -1);

	int st = 0, end = 0;
	while (end < src.length()) {
		if (src[end] == ' ') {
			reverse(src, st, end-1);
			st = end + 1;
		}
		end++;
	}
	reverse(src, st, end-1);
	cout << src.c_str() << endl;
	
	return 0;
}