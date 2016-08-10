#include<iostream>
#include<stdlib.h>
using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	int data;

	Node(int data = 0, Node* left = nullptr, Node* right = nullptr) {
		this->left = left;
		this->right = right;
		this->data = data;
	}
};

bool exists(Node* p) {
	if (p == nullptr)
		return false;
	return true;
}

bool inBSTLimits(int lowerLim, int data, int upperLim) {
	if (lowerLim <= data && data < upperLim)
		return true;
	return false;
}

Node *p, *q;

template<typename T>
class NodeQueue {
	int len;
	int front;
	int back;
	T* q;
public:
	NodeQueue(int size) {
		len = size;
		front = 0;
		back = -1;
		q = new T[size];
	}

	void enqueue(T data) {
		if (back + 1 >= len)
			return;
		back += 1;
		q[back] = data;
	}

	T pop() {
		T temp = q[front];
		front += 1;
		return temp;
	}

	void print() {
		if (len <= 0)
			return;
		cout << "\n\nQueue:\n";
		cout << "front = "<<front<<"  back="<<back<<"\n";
		for (int i = front; i <= back; i++) {
			cout << q[i] << "  ";
		}
		cout << endl;
	}

	bool isEmpty() {
		if (front > back)
			return true;
		return false;
	}



};

class BST {
public:
	int len;
	Node* root;

	BST() {
		root = nullptr;
		len = 0;
	}

	void insert(int data) {
		if (root == nullptr) {
			root = new Node(data);
			len = 1;
			return;
		}
		p = root;
		while (p != nullptr) {
			q = p;
			if (data <= p->data)
				p = p->left;
			else p = p->right;
		}
		if (data <= q->data)
			q->left = new Node(data);
		else q->right = new Node(data);
		len += 1;
	}

	void levelOrderTraversal() {
		Node* temp;
		NodeQueue<Node*> q(len);
		q.enqueue(root);
		cout << "\nLevel order:\n";
		while (!q.isEmpty()) {
			temp = q.pop();
			cout << temp->data<<"  ";
			if (temp->left != nullptr)
				q.enqueue(temp->left);
			if (temp->right != nullptr)
				q.enqueue(temp->right);
		}
		cout << endl;
	}

	bool checkIfBST() {
		if (exists(root))
			return checkIfBST_rec(root, INT_MIN, INT_MAX);
		return false;
	}

private:
	bool checkIfBST_rec(Node* p, int lowerLim, int upperLim) {
		bool temp = true;
		if (exists(p->left)) {
			if (p->left->data > p->data || !inBSTLimits(lowerLim, p->data, upperLim))
				return false;
			temp = temp & checkIfBST_rec(p->left, lowerLim, p->data);
		}
		if (exists(p->right)) {
			if (p->right->data <= p->data || !inBSTLimits(lowerLim, p->data, upperLim))
				return false;
			temp = temp & checkIfBST_rec(p->right, p->data, upperLim);
		}
		return temp;
	}

};

int main() {
	BST *b = new BST();
	b->insert(10);
	b->insert(4);
	b->insert(3);
	b->insert(15);
	b->insert(16);
	b->insert(6);
	b->insert(5);
	b->insert(6);
	b->levelOrderTraversal();
	// Is a BST:
    //              10
	//		  4           15
	//   3		   6  		   16
	//		    5
	//		       6

	cout <<"Is BST: "<< b->checkIfBST();


	b->root->left->right->data = 11;
	b->levelOrderTraversal();
	// NOT a BST:
    //             10
	//		  4           15
	//   3	      11  		   16
	//		    5
	//		       6

	cout << "Is BST: " << b->checkIfBST();
	cout << endl;
	return 0;
}
