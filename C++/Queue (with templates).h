#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;


template<typename T>
class QueueNode{
public:
	T data;
	QueueNode<T> *next;
 
	QueueNode(T x=NULL, QueueNode<T> *next_QueueNode=NULL){
		data=x;
		next=next_QueueNode;
	}
};



template<typename T>
class Queue{
private:
	QueueNode<T> *head;  //remoe from head
	QueueNode<T> *tail;	 //append to tail
	long len;
	
public:
	Queue(){
		head=NULL;
		tail=NULL;
		len=0;
	}

	void enqueue(T data){
		len+=1;	   
		if(tail==NULL){
			tail=new QueueNode<T>(data);
			head=tail;
			return;	   
		}
		tail->next=new QueueNode<T>(data);
		tail=tail->next;
	}

	void enqueue(T *arr, long len){
		long i;
		for(i=0; i<len; i++)
			enqueue(arr[i]);
	}
	
	T dequeue(){
		if(head==NULL)
			return NULL;
		T data=head->data;
		QueueNode<T> *temp=head;
		if(head==tail){
			head=NULL;
			tail=NULL;
		}
		else{
			head=head->next;
		}
		delete temp;
		len-=1;
		return data;	
	}

	
	void print(){
		QueueNode<T> *p=head;
		cout<<"\n<---Queue--->\n";
		cout<<"Head:";
		while(p!=NULL){
			cout<<"\t"<<p->data<<endl;
			p=p->next;
			if(p!=NULL and p->next==NULL)
				cout<<"Tail:";
		}
		cout<<"<---End of Queue--->\n";
		cout<<"Number of elements: "<<len<<"\n\n";
	}
	
	long length(){
		return len;
	}
	
	bool is_empty(){
		if(len==0)
			return true;
		return false;
	}

	~Queue(){
		QueueNode<T>* temp=head;
		while(head!=NULL){
			temp=head;
			head=head->next;
			delete temp;
		}
	}

};

/*

int main(){
	long i;

	long n=30000000;
	long range=100;

	Queue<double> *s=new Queue<double>();

	double *arr=new double[n];
	/*for(i=0; i<n; i++)
		arr[i]=rand()%(range) + pow(rand(),1/double(3));
		
	s->enqueue(arr, n);
	*
	long power=10;
	for(i=0; i<n; i++){
		s->enqueue(rand()%(range) + pow(rand(),1/double(3)));
		if(i%power==0){
			power=power*10;
			cout<<"\r"<<i;
		}
	}
	
	cout<<"\n"<<s->length();	
	delete arr;
	cin>>i;
	delete s;
	
	cin>>i;
	
}
*/

