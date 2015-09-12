#include<iostream>
using namespace std;

template<typename T>
class Node{
	public:
	T data;
	Node<T> *next;
	Node(T input_data=NULL, Node<T> *input_next=NULL){
		data=input_data;
		next=input_next;
	}

};

template<typename T>
class LinkedList{
	Node<T> *head;
	long len;
	public:
	LinkedList(Node<T> *input_head=NULL, long input_len=0){	
		head=input_head;
		len=input_len;
	}

	void add(T data){
		Node<T> *temp=new Node<T>(data, head);
		head=temp;
		len+=1;
	}
	
	void print(Node<T> *p=NULL){
		if(!p) p=head;
		cout<<"\n<---LINKED LIST--->\n";
		while(p!=NULL){
			cout<<p->data<<" -> ";
			p=p->next;
		}
		cout<<"NULL";
		cout<<"\n<---End of LINKED LIST--->\n";
	}
	
	private:
	Node<T>* rec_rev_main(Node<T> *p){
		if(p==NULL) 
			return NULL;
	
		Node<T> *end_node=rec_rev_main(p->next);	
		if(p->next==NULL){	   //p should be the new head, so we return it
			return p;
		}
		else{
			p->next->next=p; //reverse it	 	 
			return end_node;
		}	 	 	 
	}
	
	public:
	
	void rec_reverse(){
		Node<T> *new_last=head;	  
		head=rec_rev_main(head);
		new_last->next=NULL;
	}
		
};



int main(){

	LinkedList<int>* ll=new LinkedList<int>();
	//ll->add(2);
	//ll->add(40);
	ll->add(67);
	ll->add(7);
	ll->add(23);
	ll->print();
	ll->rec_reverse();
	ll->print();

}

