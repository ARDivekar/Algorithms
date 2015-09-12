#include<iostream>
#include<string>
#include<stdlib.h>
#include<math.h>
using namespace std;


template<typename T>
class Node{
	public:
	T data;
	Node<T> *next;
	
	Node(T x=NULL, Node<T> *next_node=NULL){
		data=x;
		next=next_node;
	}

};


template<typename T>
class LinkedList{
	private:
	long len;
	Node<T> *head;
	Node<T> *tail;
	bool isSorted;
	
	public:
	LinkedList(){
		len=0;
		isSorted=false;
		head=NULL;
		tail=NULL;
	}

	void insert(T data){ //chucks it at the front: by locality of reference, you expect to find this first
		len+=1;
		if(head==NULL){
			head=new Node<T>(data);
			tail=head;
			isSorted=true;
			return;
		}
		Node<T> *temp=new Node<T>(data);
		temp->next=head;
		head=temp;
	}

	Node<T>* find (T data){
		//if(!isSorted){ //if it is sorted, use the indexed find, which is quick
		Node<T> *p=head;
		while(p!=NULL){
			if(p->data==data){
				return p;
			}
			p=p->next;
		}	 	 	 
		return NULL;		
	}

	void remove(T data){
		if(head){
			Node<T> *p=head;			
			if(p->data==data){
				head=head->next;
				if(head==NULL) tail=NULL;
				delete p;
				return;
			}
			while(p->next!=NULL){
				if(p->next->data==data){
					Node<T> *temp=p->next;
					p->next=p->next->next;
					delete temp;
					return;
				}
				p=p->next;
			}
		}
	}

	bool is_sorted(char order){
		Node<T> *p=head;
		if(head->next==NULL)
			return true;
		if(order=='D'){
			while(p!=NULL && p->next!=NULL){
				if(p->data < p->next->data)
					return false;
				p=p->next;
			}
			return true;
		}
		else {
			while(p!=NULL && p->next!=NULL){
				if(p->data > p->next->data)
					return false;
				p=p->next;
			}
			return true;
		}
	}

	void print(){
		Node<T> *p=head;
		if(is_sorted('A')){
			isSorted=true;
			cout<<"\n<---Ascending Sorted List--->\n  ";
		}
		else if (is_sorted('D')){
			isSorted=true;
			cout<<"\n<---Descending Sorted List--->\n  ";
		}
		else cout<<"\n<---List--->\n  ";
		while(p!=NULL){
			cout<<p->data<<" -> ";
			p=p->next;
		}
		cout<<"NULL";
		cout<<"\n<---End of List--->\n";
	}
		
	void reverse(){
		if(head==tail)
			return;
		Node<T> *before=NULL;
		Node<T> *i=head;
		Node<T> *after;
		while(i!=NULL){
			after=i->next;
			i->next=before;
			before=i;
			i=after;
		}
		tail=head;
		head=before;
	}

	long length(){
		return len;	   
	}	     

	
	
	public:
  	void mergesort(){
    	if(head)
			mergesort(head);
		isSorted=true;
	}


	private:

	void mergesort(Node<T>* &node){
    	if(!node || !node->next)
			return;
      	Node<T>* front = NULL;
      	Node<T>* back = NULL;
      	split(node, front, back);
      	mergesort(front);
      	mergesort(back);
      	node = merge(front, back);
	}
	
	void split(Node<T>* source, Node<T>* &front, Node<T>* &back){	
		if(source==NULL || source->next ==NULL){
			front = source; //works if there is zero or more elements
			back = NULL;
			return;
		}
      //there are at least two elements
		Node<T>* fast = source->next; 
      	Node<T>* slow = source;
      	while(fast != NULL){
        	fast = fast->next;
        	if(fast){
            	slow = slow->next;
            	fast = fast->next;
        	}
		}
      
    	front = source;
    	back = slow->next;
    	slow->next = NULL;
	}

	

  	Node<T>* merge(Node<T>* front, Node<T>* back){
     	 if(!front)
     	 return back;
     	 if(!back)
 	    	return front;
      	Node<T> *final = 0;
  
  	    if(front->data <= back->data){
    	      final = front;
        	  final->next = merge(front->next, back);
      	}
      	else{
        	  final = back;
          	final->next = merge(front, back->next);
      	}
      	return final;
  	}

	public:
	void mergesort_iter(){
		
	}	 	 

};


int main(){

	LinkedList<double> *ll=new LinkedList<double>();
	long n=10;
	long i;
	for(i=0; i<n; i++)
		ll->insert(rand()%75+pow(rand()%74, 1/(double)3));
	ll->print();
	ll->mergesort();
	ll->print();
	ll->remove(3);
	ll->print();
	ll->reverse();
	ll->print();
	cout<<ll->length();

}

