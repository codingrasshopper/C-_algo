//Program to print all prime numbers between n1 and n2 using Sieve of earthostenes
// First create an array with all values set to one (prime), then browse array and scratch out all multiples (make them 0), final array with ones are primes



#include<iostream>
using namespace std;

void scratchmultiples( int a, int n2, int arr[] )
{
int num,i;
i=2;

while((num = i *a)<= n2)
{
	arr[num-1] = 0;
	i++;


}
}


int main()
{
int arr[20], n1, n2,i;

n1=2;
n2=20;

for (i=0; i<19 ; i++)
{
	arr[i] = 1;
	cout <<arr[i] ;
}
cout <<endl;
for (i=1; i <n2; i++)
{
	if (arr[i]==1){
		cout << "primes" <<i+1 <<endl;
		scratchmultiples (i+1,n2,arr);}




}

for (int i=0; i<n2; i++)
{cout <<arr[i]; }
}