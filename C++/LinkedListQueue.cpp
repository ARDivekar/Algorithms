#include<iostream>
#include<stdlib.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data=0) {
		this->data = data;
		next = nullptr;
	}
};
Node* temp;

class LinkedListQueue{
	Node* head;
	Node* tail;
	int len;
public:
	LinkedListQueue() {
		head = nullptr;
		tail = nullptr;
		len = 0;
	}

	int size() {
		return len;
	}

	void enqueue(int data) { // insert at head
		if (head == nullptr) {
			head = new Node(data);
			tail = head;
			len = 1;
			return;
		}
		tail->next = new Node(data);
		tail = tail->next;
		len += 1;
	}

	void dequeue() {
		if (len == 0)
			return;
		temp = head;
		head = head->next;
		delete temp;
		len -= 1;
	}

	void print() {
		temp = head;
		cout << "\nLinked List:\n";
		while (temp != nullptr) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
};


int main() {
	LinkedListQueue l;
	l.enqueue(5);
	l.enqueue(1);
	l.enqueue(2);
	l.print();
	l.enqueue(6);
	l.enqueue(4);
	l.print();
	l.dequeue();
	l.print();
	l.dequeue();
	l.dequeue();
	l.print();
	cout << "\nSize:" << l.size();
	cout << endl;
	return 0;
}
