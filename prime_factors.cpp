//Program to find largest prime factor

#include <iostream>
using namespace std;

int main()
{
long long unsigned n= 600851475143; 
int i;

if (n%2 == 0)
		{ cout << 2;}

else
{ 
	for (i=3; i<=sqrt(n); i=i+2)
		{ while (n %i == 0)
			{ cout << i << " " <<endl;
			n = n/i;
			cout << " n is" <<n <<endl;
	}
	}
if (n>2)
	cout << "largest" << n;

}



return 0;



}
