#include<iostream>
#include<vector>
#include <string>
#include<algorithm>
using namespace std;

#define RANGE 3
//program to count sort

//Works only for positive numbers
void sortcolors_onlypos(vector<int>& nums){
	int count[RANGE +1];
	int len = nums.size();
	int * output = new int[nums.size()];
	vector<int>::iterator it;

	for(int i=0; i<(RANGE +1); i++) {
		count[i] =0;
	}

	//count
	for(int i=0; i < nums.size(); i++) {
		count[nums[i]] += 1;
	}

	//sum
	for(int i=1; i <=RANGE ; i++) {
		count[i] += count[i-1];
	} 

	for(int i=0; i < nums.size(); i++) {
		output[(count[nums[i]])-1] = nums[i];
		--count[nums[i]];
	}

	for (int i=0; i<nums.size(); i++) {
		nums[i] = output[i];
	}

	for(int i=0; i < nums.size(); i++) {
		cout << nums[i];
	}
	delete [] output;
}


//Works for both positive and negative
void sortcolors(vector<int>& nums){
	int count[RANGE +1];
	int len = nums.size();
	int * output = new int[nums.size()];
	int k=*max_element(nums.begin(), nums.end());
	int m=*min_element(nums.begin(), nums.end());
	
	int n=k-m+1;
	vector<int>::iterator it;

	for(int i=0; i<(RANGE +1); i++) {
		count[i] =0;
	}

	//count
	for(int i=0; i < nums.size(); i++) {
		count[nums[i]-m] += 1;
	}

	//sum
	for(int i=1; i <=RANGE ; i++) {
		count[i] += count[i-1];
	} 

	for(int i=0; i < nums.size(); i++) {
		output[count[nums[i]-m]-1] = nums[i];
		--count[nums[i]-m];
	}

	for (int i=0; i<nums.size(); i++) {
		nums[i] = output[i];
	}

	for(int i=0; i < nums.size(); i++) {
		cout << nums[i];
	}
	delete [] output;
}



int main(){
	//vector<int> nums;
	
	int myints[] = {3,2,0,1, 2,0,0,3};    //Easy way to initialize vector instead of pushing back
	std::vector<int> nums (myints, myints + sizeof(myints) / sizeof(int) );
	/*nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(-1);*/

	sortcolors(nums);

	return 0;
}