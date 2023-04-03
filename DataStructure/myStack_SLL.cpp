#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};

class linkedStack {
public:
	Node* head;
	Node* tail;
	int n;

	linkedStack() {
		this->head = NULL;
		this->tail = NULL;
		this->n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		return n == 0;
	}
	int top() {
		if (empty()) return -1;
		else return head->data;
	}
	void push(int e) {
		Node* newNode = new Node(e);
		if (empty()) {
			head = newNode;
			tail = newNode;
			n++;
		}
		else {
			newNode->next = head;
			head = newNode;
			n++;
		}
	}
	int pop() {
		if (empty()) return -1;
		else {
			int temp = head->data;
			head = head->next;
			n--;
			return temp;
		}
	}
};

/*
	Problem : https://o365inha-my.sharepoint.com/:b:/g/personal/scyongg_office_inha_ac_kr/EcRzSCqOnaBEoRZHOa9Dbg0Btn4RWIxNLf3-Nzn-AiPwDw?e=smn3A0
	Input testcase : https://o365inha-my.sharepoint.com/:t:/g/personal/scyongg_office_inha_ac_kr/EdVlHMT_Us9Eg1MU01SAmJUBVixn7RSimfBRDCXHZP3jhA?e=wf7gMd
	Output testcase : https://o365inha-my.sharepoint.com/:t:/g/personal/scyongg_office_inha_ac_kr/EZ5qg1KhaGNKmo2eDFY3jxIBXwlgWHhml9eE2EOD5xsM_A?e=ipkBXj
*/

int main() {
	int t;
	cin >> t;

	string cmd_in;
	linkedStack Stack;
	while (t--) {
		cin >> cmd_in;

		for (int i = 0; i < cmd_in.size(); i++) {
			int stoi = cmd_in[i];
			if (0 <= stoi - '0' && stoi - '0' <= 9) {
				Stack.push(stoi - '0');
			}
			else if (stoi == '+') {
				int op1 = Stack.pop();
				int op2 = Stack.pop();
				int result = op1 + op2;
				Stack.push(result);
			}
			else if (stoi == '-') {
				int op1 = Stack.pop();
				int op2 = Stack.pop();
				int result = op2 - op1;
				Stack.push(result);
			}
			else if (stoi == '*') {
				int op1 = Stack.pop();
				int op2 = Stack.pop();
				int result = op1 * op2;
				Stack.push(result);
			}
			else if (stoi == '/') {
				int op1 = Stack.pop();
				int op2 = Stack.pop();
				int result = op2 / op1;
				Stack.push(result);
			}
		}
		cout << Stack.top() << endl;
	}
}