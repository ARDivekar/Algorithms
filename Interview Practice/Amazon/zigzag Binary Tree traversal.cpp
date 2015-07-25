/*
  	  	  1
  	   / 	  \
  	 2 	        3
   /   \      /   \
  4     5    6     7
  /\   /\    /\    /\
 8  9 10 11 12 13 14 15
Output: 1 3 2 4 5 6 7 15 14 13 12 11 10 9 8 

*/
#include<iostream>
#include<list>
using namespace std;



template<typename T>
class Queue{
	std::list<T> queue;
	public:
	void enqueue(T data){
		queue.push_back(data);
	}
	
	T dequeue(){
		T data= queue.front();
		queue.pop_front();
		return data; 
	}
	
	T peek_head(){
		return queue.front();
	}
	
	bool is_empty(){
		return queue.empty();
	}
};	  

template<typename T>
class Stack{
	std::list<T> stack;
	public:
	void push(T data){
		stack.push_front(data);
	}
	
	T pop(){
		T data= stack.front();
		stack.pop_front();
		return data; 
	}
	
	T peek_top(){
		return stack.front();
	}
	
	bool is_empty(){
		return stack.empty();
	}
};	 

template<typename T>
class Node{
	public:
	T data;
	Node<T> *left;
	Node<T> *right;
	int level;
	Node(T input_data, int input_level, Node<T> *input_left=NULL, Node<T> *input_right=NULL){
		data=input_data;
		level=input_level;
		left=input_left;
		right=input_right;
	}
	
};

	
template<typename T>
void zigzag_print(Node<T> *root){
	Stack<Node<T>*> S;
	Queue<Node<T>*> Q;
	Q.enqueue(root);
	Node<T> *temp;
	int current_level=0;
	while(!Q.is_empty()){
		temp=Q.dequeue();
		if(current_level!=temp->level){
			if(current_level%2==0){
				while(!S.is_empty())
					cout<<S.pop()->data<<" ";
			}
		}
		if(temp->level%2==1)
			cout<<temp->data<<" ";	 	 
		current_level=temp->level;
		if(temp->left){
			Q.enqueue(temp->left);	  
			if(temp->level%2==1)
				S.push(temp->left);
		}
		if(temp->right){
			Q.enqueue(temp->right);	   
			if(temp->level%2==1)
				S.push(temp->right);
		}
	}	
	while(!S.is_empty())
		cout<<S.pop()->data<<" ";
}

int main(){
	Node<int> *n15=new Node<int>(15,4);
	Node<int> *n14=new Node<int>(14,4);
	Node<int> *n13=new Node<int>(13,4);
	Node<int> *n12=new Node<int>(12,4);
	Node<int> *n11=new Node<int>(11,4);
	Node<int> *n10=new Node<int>(10,4);
	Node<int> *n9=new Node<int>(9,4);
	Node<int> *n8=new Node<int>(8,4);
	Node<int> *n7=new Node<int>(7,3,n14,n15);
	Node<int> *n6=new Node<int>(6,3,n12,n13);
	Node<int> *n5=new Node<int>(5,3,n10,n11);
	Node<int> *n4=new Node<int>(4,3,n8,n9);
	Node<int> *n3=new Node<int>(3,2,n6,n7);
	Node<int> *n2=new Node<int>(2,2,n4,n5);
	Node<int> *n1=new Node<int>(1,1,n2,n3);
	zigzag_print(n1);
}

