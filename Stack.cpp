#include <iostream>
using namespace std;

class Stack{
private:
	typedef struct node{
		int data;
		struct node* next;
	}NODE;

	NODE* top;

public:
	Stack();
	~Stack();
	void push(int);
	int pop();
	friend void print(Stack&);
};

Stack::Stack(){
	top= NULL;
}

Stack::~Stack(){
	while(top){
		NODE* tmp= top;
		top= top->next;
		delete tmp;
	}
}

void Stack::push(int n) {
	NODE* ptr = new NODE;
	ptr->next = top;
	ptr->data = n;
	top = ptr;
}


int Stack::pop() {
	NODE* tmp = top;
	int data = top->data;
	top= top->next;
	delete tmp;
	return data;
}

void print(Stack &s){
Stack::NODE* cur = s.top;

while(cur){
	cout << cur->data <<endl;
	cur = cur->next;
}
}


int main36(){
	Stack* st = new Stack;
	st->push(5);
	st->push(6);
	int x = st->pop();
	print(*st);


return 0;
}




