#include <vector>
#include <iostream>
#include <string>
using namespace std;

//only rows are in ascending order
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	int start=0, end = m*n - 1;
	int mid,e;
	while(start<=end){
		mid = start + (end-start)/2;
		e = matrix[mid/n][mid%n];

		if (target < e)
			end= mid - 1;
		else if (target > e)
			start = mid + 1;
		else
			return true;
	
	}
	return false;

}

//both rows and columns are in ascending order
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	int i=0, j=n-1;
	while (i<m && j>=0) {
		if (matrix[i][j]== target)
			return true;
		if (matrix[i][j] > target)
			j--;
		else {
			i++;
			//j= n-1;
		}
	
	}
	return false;
}



int main(){
	//vector<vector<int>> matrix (2, vector<int>(5, 3));
	vector<vector<int>> matrix;
	vector<int> row1;
	vector<int> row2;
	vector<int> row3;
	row1.push_back(1);
	row1.push_back(2);
	row1.push_back(8);
	row2.push_back(4);
	row2.push_back(6);
	row2.push_back(9);
	row3.push_back(5);
	row3.push_back(7);
	row3.push_back(17);

	matrix.push_back(row1);
	matrix.push_back(row2);
	matrix.push_back(row3);
	int target = 10;
	
	/*matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;
	matrix[1][2] = 5;*/
	cout << searchMatrix(matrix, target) ;


	return 0;
}