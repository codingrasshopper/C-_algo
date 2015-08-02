#include<iostream>
using namespace std;

int main() {
	string remove = "cat";
	string str = "catdog";
	bool flags[128];
	int src, dst, i;

	for (i=0; i < 128; i++) {
		flags[i] = false;
	}

	for (src=0; src < remove.length(); src++) {
		flags[remove[src]] = true;
	}

	src=0; dst = 0;
	while (src < str.length()) {
		if (!flags[(int)str[src]]) {
			str[dst++] = str[src];
		}
		++src;
	}

	cout << string(str,0,dst).c_str() <<endl;

	return 0;
}