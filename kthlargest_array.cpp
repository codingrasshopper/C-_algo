#include<iostream>
using namespace std;


void swap (int* a, int* b) {
	int temp;
	temp=*a; *a=*b; *b=temp; }

int partition(int arr[], int k, int lo, int hi) {
	int firsthigh, p;
	p = hi;
	firsthigh = lo;

	
	for (int i=lo; i<hi; i++) {
			if (arr[i] > arr[p]) {
				swap ( &arr[i], &arr[firsthigh]);
				firsthigh++;
			}
		}
	swap (&arr[p], &arr[firsthigh]);
	return firsthigh;
}

int quick(int arr[], int k, int lo, int hi) {
	int p;
	if (k>0 && k<=(hi-lo+1)) {
	p = partition(arr, k, lo, hi);
	if ((p-lo) == (k-1))
		return arr[p];
	if ((p - lo) > (k-1))
		return quick(arr, k, lo, (p-1));
	return quick(arr,(k-p+lo-1), (p+1), hi);

}

}

int main(){
	int arr[] = {19, 3,9,10};
	int k=2;
	int n = sizeof(arr)/sizeof(arr[0]);
	int lo=0, hi = n-1;
	cout << quick(arr, k, lo, hi);

	return 0;
}