#include<iostream>
#include<map>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

//Find k most frequent elements in array

bool myFunction(std::pair<int,int> first, std::pair<int,int> second)
{
	return (first.second > second.second);
}

int main41(){
	std::map<int,int> mymap;
	int num[] = {4,1,2,3,1,1,2,4,4,1,5,6,4};
	int len = sizeof(num)/sizeof(num[0]);
	map<int, int>::iterator it;
	int k =3;

	for (int i=0; i< len; i++){
		mymap[num[i]] += 1;	

	}

	for( it=mymap.begin(); it!=mymap.end(); ++it) {
		cout << (*it).first << ": " << (*it).second << endl;
	}

	cout << "sort" <<endl;
	std::vector<std::pair<int, int> > myVec(mymap.begin(), mymap.end());
	std::sort(myVec.begin(), myVec.end(), &myFunction);

	for(int i = 0; i < myVec.size(); i++) {
		cout << myVec[i].first << ", " << myVec[i].second << endl;
	}

	cout << "Top K elements are..."<<endl;
	for(int i=0; i<k; i++) {
		cout << myVec[i].first << endl;	
	}

	return 0;
}