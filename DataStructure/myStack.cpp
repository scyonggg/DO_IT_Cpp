
/////// 23.03.06 
/*
	integer type Stack implementation with Linked List
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
	friend class myStack;
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node();
	Node(int data);
	~Node();
};

Node::Node() : Node(NULL) {}
Node::Node(int data) {
	this->data = data;
	this->next = NULL;
	this->prev = NULL;
}
Node::~Node() {
	this->data = NULL;
	this->next = NULL;
	this->prev = NULL;
}

class myStack {
private:
	Node* head;
	Node* tail;
public:
	myStack();
	~myStack();

	bool isEmpty();
	void printAll();
	void Push(int data);
	int Pop();
	int Top();
};

myStack::myStack() {
	this->head = NULL;
	this->tail = NULL;
}
myStack::~myStack() {
	this->head = NULL;
	this->tail = NULL;
}
bool myStack::isEmpty() {
	return (this->head == NULL) ? true : false;
}
void myStack::printAll() {
	if (this->isEmpty()) {
		cout << "The stack is empty" << '\n';
		return;
	}
	else {
		Node* ptr = this->head;
		while (ptr != NULL) {
			cout << ptr->data << ' ';
			ptr = ptr->next;
		}
		cout << '\n';
		return;
	}
}
void myStack::Push(int data) {
	Node* newNode = new Node(data);
	if (this->isEmpty()) {
		head = newNode;
		tail = newNode;
		return;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		return;
	}
}
int myStack::Pop() {
	if (this->isEmpty()) {
		cout << "The stack is empty" << '\n';
		return -1;
	}
	else {
		int ret = tail->data;
		if (head == tail) {
			delete head;
			head = NULL;
			tail = NULL;
			return ret;
		}
		else {
			Node* temp = tail;
			tail = tail->prev;
			delete temp;
			temp = NULL;
			tail->next = NULL;
			return ret;
		}
	}
}
int myStack::Top() {
	if (this->isEmpty()) {
		cout << "The stack is empty" << '\n';
		return -1;
	}
	else {
		return tail->data;
	}
}

int main() {
	myStack myStack;

	cout << ((bool(myStack.isEmpty())) ? "True" : "False") << '\n';
	myStack.Push(1);
	myStack.printAll();
	myStack.Push(2);
	myStack.printAll();
	myStack.Push(3);
	myStack.printAll();
	myStack.Top();
	myStack.printAll();
	myStack.Pop();
	myStack.printAll();
	myStack.Pop();
	myStack.printAll();
	myStack.Pop();
	myStack.printAll();
	myStack.Pop();
	myStack.printAll();
}