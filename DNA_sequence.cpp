#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;

vector<string> findRepeatedDnaSequences(string s);
long str2long(string s){
        long res = 0;
        for (int i=0;i<10;i++){
            if (s[i] == 'A'){res = res*10 + 1;}
            if (s[i] == 'T'){res = res*10 + 2;}
            if (s[i] == 'C'){res = res*10 + 3;}
            if (s[i] == 'G'){res = res*10 + 4;}
        }
        return res;
    }
    string long2str(long s){
        string res = "";
        for (int i=0;i<10;i++){
            int d = s%10;
            if (d == 1) {res= res+ "A" ;}
            if (d == 2) {res= res+ "T" ;}
            if (d == 3) {res= res+ "C" ;}
            if (d == 4) {res= "G" + res;}
            s = s /10;
        }
        return res;
    }

vector<string> findRepeatedDnaSequences(string s){
	map<string, int> mymap;
	map<string,int>::iterator it;
	vector<string> res;
	string sub;
	if (s.size() <10) return res;
	for(int i=0; i<(s.size() - 9); i++){
		sub= s.substr(i,10);
		if (mymap.find(sub) == mymap.end()){
			mymap[sub] = 0;
		}
		else{
			mymap[sub] += 1;
		}
	
	}

	for (it= mymap.begin(); it!= mymap.end(); it++){
		if(it->second >=1) 
			res.push_back(it->first);
	}

	return res;
}





int main(){
	//string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	string s="AA";
	vector<string> result;
	result =  findRepeatedDnaSequences(s);
	for(int i=0; i<result.size(); i++)
		cout << result[i]<< endl;
	cout << long2str(123);
	return 0;
}