#include<iostream>
#include<map>
using namespace std;


bool isomorphic(string s,string t){
	map<char, char> mymap;
	map<char, char> mymap2;
	for(int i=0; i<s.size(); i++){
		if(mymap.find(s[i]) == mymap.end() && mymap2.find(t[i]) == mymap2.end()){
			mymap[s[i]] = t[i];
			mymap2[t[i]] = s[i];
		}
		else {
			if((mymap[s[i]] != t[i]) || (mymap2[t[i]] != s[i]))
				return false;
		}

	}
	
	return true;

}






int main(){
	

	string s="ab";
	string t="ca";

	cout << isomorphic(s,t);

	return 0;
}