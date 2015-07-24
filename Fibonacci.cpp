
//Program to find sum of Fibonacci numbers below 4 million which are even

#include <iostream>
using namespace std;

int main()
{
int fib=0, a, b;
a = 1;
b = 2;

cout << a  << " ";
cout << b << " ";
int n = 3, sum = 2;

while (a+b <4000000) { 

fib = a + b;
a = b;
b = fib;
cout << fib << " ";
if (fib%2 == 0) { sum += fib;}
 n += 1;

} 


cout << "sum" << sum;

return 0;

}
