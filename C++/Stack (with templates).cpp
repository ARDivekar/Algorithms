#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;



template<typename T>
class Node{
public:
	T data;
	Node *next;

	Node(T x=NULL, Node *next_node=NULL){
		data=x;
		next=next_node;
	}


};

template<typename T>
class Stack{
	private:
	Node<T> *top;
	long len;
	
	public:
	Stack(){
		top=NULL;
		len=0;
	}
	void push(T data){
		len+=1;
		if (top==NULL){
			top=new Node<T>(data);
			return;
		}
		Node<T> *temp=top;
		top=new Node<T>(data);
		top->next=temp;
		
	}

	void push(T *arr, long input_len){
		long i;
		for(i=0; i<input_len; i++)
			push(arr[i]);
	}

	T pop(){
		if(top==NULL){
			return -1;
		}
		T data=top->data;
		Node<T> *temp=top;
		top=top->next;
		delete temp;
		len-=1;
		return data;
		
		
	}	 

	void print(){
		if(len==0){
			cout<<"\n<---Stack is empty--->"; 
			return;
		}
		cout<<"<---Stack--->\n"; 
		Node<T> *p=top;
		while (p!=NULL){
			cout<<"  "<<p->data<<endl;
			p=p->next;
		}
		cout<<"<---End of Stack--->\n"; 
		cout<<"\nNumber of elements in stack: "<<len<<"\n\n\n\n";	 	 
	}

	~Stack(){
		Node<T>* temp=top;
		while(top!=NULL){
			temp=top;
			top=top->next;
			delete temp;
		}
	}	   
		
};



int main(){
	long i;

	long n=5;
	double *arr=new double[n];
	for(i=0; i<n; i++)
		arr[i]=rand()%(2*n) + pow(rand(),1/double(3));


	Stack<double> *s=new Stack<double>();
	s->push(arr, n);
	s->print();

	for(i=0; i<n+2; i++){
		s->pop();
		s->print();
	}
	
}

