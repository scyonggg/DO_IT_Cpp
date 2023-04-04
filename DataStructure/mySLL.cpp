#include <iostream>

using namespace std;

struct node {
    int data;
    node* NextNode;
};

class LinkedList {
private:
    node* head;
    node* tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addFrontNode(int n);
    void addNode(int n);

    void insertNode(node* prevNode, int n);
    void deleteNode(node* prevNode);

    node* getHead() {
        return head;
    }
    void display(node* head);
};

void LinkedList::addFrontNode(int n) {
    node* temp = new node;
    temp->data = n;

    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        temp->NextNode = head;
        head = temp;
    }
}

void LinkedList::addNode(int n) {
    node* temp = new node;
    temp->data = n;
    temp->NextNode = NULL;

    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->NextNode = temp;
        tail = temp;
    }
}

void LinkedList::insertNode(node* prevNode, int n) {
    node* temp = new node;
    temp->data = n;

    temp->NextNode = prevNode->NextNode;
    prevNode->NextNode = temp;
}

void LinkedList::deleteNode(node* prevNode) {
    node* temp = prevNode->NextNode;
    prevNode->NextNode = temp->NextNode;
    delete temp;
}

void LinkedList::display(node* head) {
    if(head == NULL) {
        cout << "\n";
    }
    else {
        cout << head->data << " ";
        display(head->NextNode);
    }
    // cout << endl;
}

int main() {
	LinkedList a;
	//1�߰�
	a.addNode(1);
	//2�߰�
	a.addNode(2);
	//3�߰�
	a.addNode(3);

	//display
	cout << "1,2,3�� LinkedList�� �߰�\n";
	a.display(a.getHead());

	//0�� ���� �տ� �߰�
	a.addFrontNode(0);

	//1�� �׹�°�� �߰�
	a.insertNode(a.getHead()->NextNode->NextNode, 1);
	cout << "0�� ù��°�� �߰�, 1�� �׹�°�� �߰�\n";
	a.display(a.getHead());

	//����° ��� ����
	a.deleteNode(a.getHead()->NextNode);

	//display
	cout << "����° ��带 ����\n"; 
	a.display(a.getHead());

}
