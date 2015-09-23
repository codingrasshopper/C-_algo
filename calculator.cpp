#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*int calculate(string s) {
	stack<int> t;
	t.push(1);
	int sum=0, temp=0, lastsign=1;

	for(auto c:s){
		if (c=='(') t.push(lastsign);
		else if (c==')') t.pop();
		if(c>='0' || c<='9') {
			temp = temp*10 +c - '0';
		}
		if(c=='-' || c=='+') {
			sum += lastsign*temp;
			temp = 0;
			lastsign=(c=='-' ? -1 :1)*t.top();
		}
	
	}
	sum += lastsign * temp;
	return sum;
	
}*/

int calculate(string s) {
        // the given expression is always valid!!!
        // only + and - !!!
        // every + and - can be flipped base on it's depth in ().
        stack<int> signs;
        int msign = 1;
        int num = 0;
        int ans = 0;

        // always transform s into ( s )
        signs.push(1);

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = 10 * num + c - '0';
            } else if (c == '+' || c == '-') {
                ans = ans + signs.top() * msign * num;
                num = 0;
                msign = (c == '+' ? 1 : -1);
            } else if (c == '(') {
                signs.push(msign * signs.top());
                msign = 1;
            } else if (c == ')') {
                ans = ans + signs.top() * msign * num;
                num = 0;
                signs.pop();
                msign = 1;
            }
        }

        if (num) {
            ans = ans + signs.top() * msign * num;
        }

        return ans;
    }

int main(){
	string s;
	s = "1 +(2+3)-4";
	cout << calculate(s);

	return 0;
}