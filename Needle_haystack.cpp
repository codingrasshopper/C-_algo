#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;



char* strstr1(char* haystack, char* needle){

	char* p1 = haystack;

	if(!*needle){
		return p1;
	}
	while(*p1){
		char* p1begin = p1;
		char* p2 = needle;
		while((*p1== *p2) && *p1 && *p2){
			p1++;
			p2++;

		}
		if (!*p2) return p1begin;
		p1 = p1begin +1;
	}
	return NULL;
}

int strstr2(string haystack, string needle){

	if (needle.length() > haystack.length()) { return -1;}

	if(needle == ""){
		return 0;
	}

	int i=0, j=0;

	while(i < (haystack.length() - needle.length() + 1))
	{
		while(((i+j) <haystack.length() )&& (j < needle.length()) && (haystack[i+j] == needle[j])) {
			j++;	
		}
		if (j == (needle.length())) return i;
		i++;
		j=0;
	}
	return -1;
}

int main40(){

	char haystack[] = "mississippi";
	char needle[]= "bam";
	char * res;
	res = strstr1(haystack,needle);
	strncpy (res,"sample",6);
	puts(haystack);

	/*string hay = "mississippi";
	string  need= "issipi";
	int result;
	result = strstr2(hay,need);
	cout << result;*/


	/*char str[] ="This is a simple string";
	char * pch;
	pch = strstr (str,"bam");
	strncpy (pch,"sample",6);
	puts (str);*/


	return 0;
}

