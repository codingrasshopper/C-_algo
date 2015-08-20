#include<iostream>
#include<map>
#include <string>
using namespace std;

typedef std::map<int, std::string> mymap;
typedef std::pair<int, std::string> mypair;

int main32(){

	mymap primap;
	primap.insert(mypair (3, "mike"));
	primap.insert(mypair (56, "lol"));
	

	primap[1]= "Tom";
	primap[2] = "Jack";

	mymap::iterator it;
	mymap::iterator it1 = primap.find(2);
	//primap.erase(it1);

	//primap.clear();
	
	for (it= primap.begin(); it != primap.end() ; it++){
		cout << it->first << "-->" ;
		cout << it->second  <<endl;
	}

	//cout << it->second;

return 0;




}