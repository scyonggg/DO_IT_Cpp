
#include <iostream>

using namespace std;

class Node {
    friend class DLL;
private:
    int data;
    Node* next;
    Node* prev;
public:
    Node();
    Node(int data);
    ~Node();
};

class DLL {
private:
    Node* head;
    Node* tail;
    Node* cursor;
public:
    DLL();
    ~DLL();
    void insertNode(int);
    void deleteNode(int);
    void traversal();
    void reverseTraversal();
    int size();
};

Node::Node() {
    this->prev = NULL;
    this->next = NULL;
}

Node::Node(int data) {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
}

Node::~Node() {}

DLL::DLL() {
    head = new Node();
    tail = new Node();
    cursor = new Node();
    head->next = tail;
    tail->prev = head;
}

DLL::~DLL() {}

void DLL::insertNode(int data) {
    Node* temp = new Node(data);
    cursor = head->next;
    head->next = temp;
    cursor->prev = temp;
    temp->prev = head;
    temp->next = cursor;
}

void DLL::deleteNode(int data) {
    if(head->next == tail) cout << "No node exists" << endl;
    else {
        cursor = head->next;
        while(cursor != tail) {
            if(cursor->data == data) {
                cursor->prev->next = cursor->next;
                cursor->next->prev = cursor->prev;
                delete cursor;
                return;
            }
            else cursor = cursor->next;
        }
        cout << "No node to delete" << endl;
    }
}

void DLL::traversal() {
    if(head->next == tail) cout << "No node exists" << endl;
    else {
        cursor = head->next;
        while(cursor != tail) {
            cout << cursor->data << " ";
            cursor = cursor->next;
        }
        cout << endl;
    }
}

void DLL::reverseTraversal() {
    if(head->next == tail) cout << "No node exists" << endl;
    else {
        cursor = tail->prev;
        while(cursor != head) {
            cout << cursor->data << " ";
            cursor = cursor->prev;
        }
        cout << endl;
    }
}

int DLL::size() {
    int size = 0;
    if(head->next == tail) return size;
    else {
        cursor = head->next;
        while(cursor != tail) {
            size++;
            cursor = cursor->next;
        }
        return size;
    }
}

int main() {

    DLL dll;
    dll.insertNode(1);
    dll.insertNode(2);
    dll.insertNode(3);
    dll.traversal();
    dll.reverseTraversal();
    cout<<"After deleteNode"<<endl;
    dll.deleteNode(3);
    dll.traversal();
    dll.reverseTraversal();
    cout<<"size: "<<dll.size()<<endl;

    return 0;
}
