#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

    stack<int> stack1;
    stack<int> stack2;
    
    // Push element x to the back of queue.
    void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
		//if (stack2.empty() && stack1.empty()) cout <<"both are empty" ;
        if (stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
				stack1.pop();
            }
            stack2.pop();
        }
		else
        stack2.pop();
    }

    // Get the front element.
    int peek(void) {
		if (stack2.empty() && stack1.empty()) return 0;

        if (stack2.empty()){
			while(!stack1.empty()){
                stack2.push(stack1.top());
				stack1.pop();
            }
            return stack2.top();
        }
		
		//assert (stack2.empty() && stack1.empty());
        return stack2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        
        return(stack1.empty() && stack2.empty());
        
    }

	int main47(){
		push(1);
		pop();
		push(2);
		cout << peek();
	
	
		return 0;
	}