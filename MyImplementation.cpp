// // // // #include <iostream>

// // // // using namespace std;

// // // // struct node {
// // // //     int data;
// // // //     node* NextNode;
// // // // };

// // // // class LinkedList {
// // // // private:
// // // //     node* head;
// // // //     node* tail;
// // // // public:
// // // //     LinkedList() {
// // // //         head = NULL;
// // // //         tail = NULL;
// // // //     }

// // // //     void addFrontNode(int n);
// // // //     void addNode(int n);

// // // //     void insertNode(node* prevNode, int n);
// // // //     void deleteNode(node* prevNode);

// // // //     node* getHead() {
// // // //         return head;
// // // //     }
// // // //     void display(node* head);
// // // // };

// // // // void LinkedList::addFrontNode(int n) {
// // // //     node* temp = new node;
// // // //     temp->data = n;

// // // //     if(head == NULL) {
// // // //         head = temp;
// // // //         tail = temp;
// // // //     }
// // // //     else {
// // // //         temp->NextNode = head;
// // // //         head = temp;
// // // //     }
// // // // }

// // // // void LinkedList::addNode(int n) {
// // // //     node* temp = new node;
// // // //     temp->data = n;
// // // //     temp->NextNode = NULL;

// // // //     if(head == NULL) {
// // // //         head = temp;
// // // //         tail = temp;
// // // //     }
// // // //     else {
// // // //         tail->NextNode = temp;
// // // //         tail = temp;
// // // //     }
// // // // }

// // // // void LinkedList::insertNode(node* prevNode, int n) {
// // // //     node* temp = new node;
// // // //     temp->data = n;

// // // //     temp->NextNode = prevNode->NextNode;
// // // //     prevNode->NextNode = temp;
// // // // }

// // // // void LinkedList::deleteNode(node* prevNode) {
// // // //     node* temp = prevNode->NextNode;
// // // //     prevNode->NextNode = temp->NextNode;
// // // //     delete temp;
// // // // }

// // // // void LinkedList::display(node* head) {
// // // //     if(head == NULL) {
// // // //         cout << "\n";
// // // //     }
// // // //     else {
// // // //         cout << head->data << " ";
// // // //         display(head->NextNode);
// // // //     }
// // // //     // cout << endl;
// // // // }

// // // // int main() {
// // // // 	LinkedList a;
// // // // 	//1추가
// // // // 	a.addNode(1);
// // // // 	//2추가
// // // // 	a.addNode(2);
// // // // 	//3추가
// // // // 	a.addNode(3);

// // // // 	//display
// // // // 	cout << "1,2,3을 LinkedList에 추가\n";
// // // // 	a.display(a.getHead());

// // // // 	//0을 제일 앞에 추가
// // // // 	a.addFrontNode(0);

// // // // 	//1을 네번째에 추가
// // // // 	a.insertNode(a.getHead()->NextNode->NextNode, 1);
// // // // 	cout << "0을 첫번째에 추가, 1을 네번째에 추가\n";
// // // // 	a.display(a.getHead());

// // // // 	//세번째 노드 삭제
// // // // 	a.deleteNode(a.getHead()->NextNode);

// // // // 	//display
// // // // 	cout << "세번째 노드를 삭제\n"; 
// // // // 	a.display(a.getHead());

// // // // }

// // // #include <iostream>

// // // using namespace std;

// // // class Node {
// // // public:
// // //     int data;
// // //     Node* next;
// // // };

// // // void printList(Node* head) {
// // //     Node* cursor = new Node;
// // //     if(head == NULL) {
// // //         cout << "The head is NULL";
// // //     }
// // //     else {
// // //         cursor = head->next;
// // //         while(cursor != NULL) {
// // //             cout << cursor->data << " ";
// // //             cursor = cursor->next;
// // //         }
// // //     }
// // // }

// // // Node* insert(Node* head, int new_data) {
// // //     if (head == NULL) {
// // //         cout << "The head is NULL";
// // //         return head;
// // //     }
// // //     Node* temp = new Node();
// // //     temp->data = new_data;
// // //     temp->next = head->next;
// // //     head->next = temp;
// // //     return head;
// // // }

// // // Node* deleteNode(Node* head, int key) {
// // //     if (head == NULL) {
// // //         cout << "The head is NULL";
// // //         return head;
// // //     }
// // //     Node* cursor = new Node();
// // //     cursor = head;
// // //     while(cursor->next->data != key) {
// // //         cursor = cursor->next;
// // //     }
// // //     Node* temp = new Node;
// // //     temp = cursor->next;
// // //     cursor->next = temp->next;  // cursor->next = cursor->next->next; ?
// // //     delete temp;
// // //     return head;
// // // }

// // // void insertAfter(Node* prev_node, int new_data) {
// // //     if (prev_node == NULL) {
// // //         cout << "The given previous node cannot be NULL";
// // //         return;
// // //     }

// // //     Node* new_node = new Node;
// // //     new_node->data = new_data;
// // //     new_node->next = prev_node->next;
// // //     prev_node->next = new_node;
// // // }

// // // int main() {
// // //     Node* head = new Node;
// // //     head = insert(head, 1);
// // //     head = insert(head, 2);
// // //     head = insert(head, 3);
// // //     printList(head);
// // //     cout << endl;
// // //     head = deleteNode(head, 2);
// // //     printList(head);
// // //     cout << endl;

// // //     return 0;
// // // }

// // #include <iostream>

// // using namespace std;

// // class Node {
// //     friend class DLL;
// // private:
// //     int data;
// //     Node* next;
// //     Node* prev;
// // public:
// //     Node();
// //     Node(int data);
// //     ~Node();
// // };

// // class DLL {
// // private:
// //     Node* head;
// //     Node* tail;
// //     Node* cursor;
// // public:
// //     DLL();
// //     ~DLL();
// //     void insertNode(int);
// //     void deleteNode(int);
// //     void traversal();
// //     void reverseTraversal();
// //     int size();
// // };

// // Node::Node() {
// //     this->prev = NULL;
// //     this->next = NULL;
// // }

// // Node::Node(int data) {
// //     this->data = data;
// //     this->prev = NULL;
// //     this->next = NULL;
// // }

// // Node::~Node() {}

// // DLL::DLL() {
// //     head = new Node();
// //     tail = new Node();
// //     cursor = new Node();
// //     head->next = tail;
// //     tail->prev = head;
// // }

// // DLL::~DLL() {}

// // void DLL::insertNode(int data) {
// //     Node* temp = new Node(data);
// //     cursor = head->next;
// //     head->next = temp;
// //     cursor->prev = temp;
// //     temp->prev = head;
// //     temp->next = cursor;
// // }

// // void DLL::deleteNode(int data) {
// //     if(head->next == tail) cout << "No node exists" << endl;
// //     else {
// //         cursor = head->next;
// //         while(cursor != tail) {
// //             if(cursor->data == data) {
// //                 cursor->prev->next = cursor->next;
// //                 cursor->next->prev = cursor->prev;
// //                 delete cursor;
// //                 return;
// //             }
// //             else cursor = cursor->next;
// //         }
// //         cout << "No node to delete" << endl;
// //     }
// // }

// // void DLL::traversal() {
// //     if(head->next == tail) cout << "No node exists" << endl;
// //     else {
// //         cursor = head->next;
// //         while(cursor != tail) {
// //             cout << cursor->data << " ";
// //             cursor = cursor->next;
// //         }
// //         cout << endl;
// //     }
// // }

// // void DLL::reverseTraversal() {
// //     if(head->next == tail) cout << "No node exists" << endl;
// //     else {
// //         cursor = tail->prev;
// //         while(cursor != head) {
// //             cout << cursor->data << " ";
// //             cursor = cursor->prev;
// //         }
// //         cout << endl;
// //     }
// // }

// // int DLL::size() {
// //     int size = 0;
// //     if(head->next == tail) return size;
// //     else {
// //         cursor = head->next;
// //         while(cursor != tail) {
// //             size++;
// //             cursor = cursor->next;
// //         }
// //         return size;
// //     }
// // }

// // int main() {

// //     DLL dll;
// //     dll.insertNode(1);
// //     dll.insertNode(2);
// //     dll.insertNode(3);
// //     dll.traversal();
// //     dll.reverseTraversal();
// //     cout<<"After deleteNode"<<endl;
// //     dll.deleteNode(3);
// //     dll.traversal();
// //     dll.reverseTraversal();
// //     cout<<"size: "<<dll.size()<<endl;

// //     return 0;
// // }

// typedef int Type;

// class Node {
//     friend class Stack;
// private:
//     Type data;
// public:
//     Node();
//     Node(Type data);
//     ~Node();
// };

// Node::Node(){
//     this->data = 0;
// }

// Node::Node(Type data){
//     this->data = data;
// }

// Node::~Node(){}

// class Stack {
// private:
//     int top;
//     int maxSize;
//     Node* nodes;
// public:
//     Stack();
//     ~Stack();

//     bool isEmpty();
//     void printStack();
//     void Push(Type data);
//     Type Pop();
//     void Clear();
// }

// Stack::Stack(int maxSize){
//     this->top = -1;
//     this->maxSize = maxSize;
//     this->nodes = new Type[maxSize];
// }

// Stack::~Stack(){
//     this->top = -1;
//     this->maxSize = 0;
//     delete [] this->nodes;
// }

// bool Node::isEmpty(){
//     if (this->top == -1)    return true;
//     else    return false;
// }

// void Node::printStack(){
//     if (this->top == -1) {
//         return;
//     }
//     else {
//         for(int i = 0; i < top; i++) {
//             cout << nodes[i].data << ' ';
//         }
//     }
//     cout << '\n';
// }

// void Node::Push(Type data){
//     if (top > maxSize) return;
//     else    nodes[++top].data = data;
// }

// Type Node::Pop() {
//     if (top == -1) return -1;
//     else return nodes[top--].data;
// }

// void Node::Clear(){
//     top = -1;
// }


/////// 23.03.03 Stack implementation by Linked List

#include <iostream>

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