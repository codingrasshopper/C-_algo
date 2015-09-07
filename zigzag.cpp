#include<iostream>
#include<string>
using namespace std;

int main48(){
	string s="PAYPALISHIRING";
	int numRows = 3;
	string r;

	const int len = (int)s.length();
    string *str = new string[numRows];

    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);
		cout << "str, s, row " << str[row]<< "-"<< s[i] << "-"<< row<<endl;
        if (row == 0)
            step = 1;
        else if (row == numRows - 1)
            step = -1;

        row += step;
    }
	
    s.clear();
    for (int j = 0; j < numRows; ++j)
    {
        s.append(str[j]);
    }
	cout << str;

	delete [] str;
	return 0;
}