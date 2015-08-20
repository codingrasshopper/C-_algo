#include <iostream>
using namespace std;

//Program to implement memcpy, always use temp buffer to overcome overlap

void memcpy(void *dest, void *src, int n)
{
	char* tmp = new char[n];
	char* csrc = (char*)src;
	char* cdest= (char*)dest;

	for(int i=0;i<n; i++){
		tmp[i] = csrc[i];

	for(int i =0; i<n;i++){
		cdest[i] = tmp[i];

	}


	}}


int main(){
	char src[] = "HiHello";
	char dst[100];

	int len = strlen(src) +1;
	memcpy(dst, src, len);
	for (int i=0; i<len; i++)
     printf("%c ", dst[i]);



	return 0;
}