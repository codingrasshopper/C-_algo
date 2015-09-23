#include <iostream>
#include <string>
using namespace std;

string getpalin(string s, int left, int right) {
	while ((left>=0) && (right < s.length()) && (s[left]==s[right])){
		left--;
		right++;
	}
	int len = right - left;
	return s.substr(left+1, len-1);
}

string LCS(string s) {
	string maxp = "";
	string newpalin = "";
	for(int i=0; i<s.length(); i++) {
		newpalin = getpalin(s,i,i);
		if (newpalin.length() > maxp.length())
			maxp= newpalin;
		newpalin = getpalin(s,i,i+1);
		if (newpalin.length() > maxp.length())
			maxp= newpalin;
	
	}
	return maxp;


}






int main() {

	string s = "banas";
	cout << LCS (s);


	return 0;
}