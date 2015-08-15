#include<iostream>
using namespace std;
typedef struct node Node;

struct node {
	int data;
	Node* next;
};


Node* BuildOneTwoThree() {
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	//head = maListNodeoc(sizeof(Node)); // aListNodeocate 3 nodes in the heap
	head = new Node;
	second = new Node;
	third = new Node;

	head->data = 1; // setup first node
	head->next = second; // note: pointer assignment rule

	second->data = 2; // setup second node
	second->next = third;

	third->data = 3; // setup third link
	third->next = NULL;

	//cout << head->data << "-" << second->data << "-" <<  third->data;
	// At this point, the linked list referenced by "head"
	// matches the list in the drawing.
	return head;
}

void display(Node* head){
	Node* current = head;
	while (current){
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void initnode(Node* head, int n){
	head->data = n;
	head->next= NULL;
}


void Push(Node** headref, int data){
	Node* newnode = new Node;

	newnode->data= data;
	newnode->next = *headref;
	*headref = newnode;
}

void AppendNode(Node** headref, int num){
	Node* current = *headref;
	Node* newnode = new Node;
	newnode-> data = num;
	newnode-> next = NULL;

	if (current == NULL) {
		*headref = newnode;
	}
	else{
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newnode;
	}
}


int pop(Node** headref){
	Node* current = *headref;
	Node* newhead = current->next;
	int res = current->data;
	free(current);
	*headref = newhead;
	return res;

}






int main31()
{ 
	//Node* head = BuildOneTwoThree();
	Node* head = new Node;
	Node* head1 = new Node;
	initnode(head,4);
	//Push(&head, 5);
	AppendNode(&head, 5);
	int res1 = pop(&head);
	display(head);
	
	
	
	
	//cout << "data popped" << res1 << endl;
	
	
	initnode(head1,6);
	//Push(&head1, 7);
	AppendNode(&head1, 7);
	display(head1);



	
	return 0;
}