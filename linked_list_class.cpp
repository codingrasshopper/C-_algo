#include<iostream>
using namespace std;

class ListNode {
public:
	ListNode* next;
	int val;

	ListNode(int x) {
		val = x;
		next = NULL;
	}

	void append(int x) {
		ListNode* curNode = this;
		while (curNode->next != NULL) {
			curNode = curNode->next;
		}

		curNode->next = new ListNode(x);
	}

	void display() {
		ListNode* curNode = this;
		while (curNode) {
			cout << curNode->val << " ";
			curNode = curNode->next;
		}
		cout << endl;
	}

	ListNode* push(int x){
		ListNode* newnode = new ListNode(x);
		newnode->val = x;
		newnode->next = this;
		return newnode;
	}
		

};

ListNode* addTwoLists(ListNode* one, ListNode* two) {
	ListNode* result = NULL;
	int sum=0, carry = 0, data;
	while(one != NULL || two != NULL){
		sum = carry;
		if (one != NULL){
			sum += one->val;
		    one = one->next;
		}
		if (two != NULL){
			sum += two->val;
			two = two->next;
		}
		carry = (sum) / 10;
		data = sum %10;
		if (result == NULL) {
			result = new ListNode(data);
		} else {
			result->append(data);
		}
	}
	
	if (carry > 0){
		result->append(carry);
	}
	return result;
}


int main25()
{ 

	ListNode* head = new ListNode(9);
	head->append(10);
	head = head->push(5);
	head = head->push(1);

	head->display();

	//ListNode* two = new ListNode(1);
	//two->append(3);
	//two->display();

	//ListNode* res = addTwoLists(head, two);
	//res->display();
	return 0;
}