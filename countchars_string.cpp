#include<iostream>
#include<vector>
#include <string>
using namespace std;

//Program to find number of same characters in string , AAABBC should be 3A2B1C

int main35(){

	string sstr = "AAABBC";
	char dstr[40];
	string dst;

	/*string a = "hi";
	char b[40];
	sprintf(b, "%d", 3);
	string c = a + b;
	cout << c; */
	
	
	int i, j, count;
	i=0,j=1, count =1;

	while (i < sstr.length()){
		while (sstr[i] == sstr[j]){
			count++;
			j++;
		}
		
		sprintf(dstr, "%d%c", count, sstr[i]);
		dst += dstr ;
		//dstr += char(count) + sstr[i];
		count=0;
		i =j;
	}

	//cout << dstr.c_str();
	cout << dst;
	


return 0;

}