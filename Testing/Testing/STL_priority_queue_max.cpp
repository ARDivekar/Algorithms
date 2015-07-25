#include<queue> //for max-heap priority queue

#ifndef IOSTREAM
#define IOSTREAM
	#include<iostream>
#endif

using namespace std;

template<typename T>
class Node {
public:
	T data;
	Node<T> *next;
	Node(T input_data=NULL) {
		data = input_data;
		next = NULL;
	}
	
	bool operator<(const Node<T> &A) const{ //operator overloading
		if (data < A.data)
			return true;
		else return false;
	}

	bool operator>(const Node<T> &A) const { //operator overloading
		if (data > A.data)
			return true;
		else return false;
	}
	
};


void pq_max_test1() {
	std::priority_queue<Node<int>> pq_max;
	pq_max.push(*(new Node<int>(5)));
	pq_max.push(*(new Node<int>(6)));
	pq_max.push(*(new Node<int>(4)));
	pq_max.push(*(new Node<int>(8)));
	pq_max.push(*(new Node<int>(1)));
	pq_max.push(*(new Node<int>(3)));
	pq_max.push(*(new Node<int>(5)));
	
	while (!pq_max.empty()) {
		cout << pq_max.top().data<< " ";
		pq_max.pop();
	}
}
