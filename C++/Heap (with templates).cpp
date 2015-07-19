#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<ctime>
using namespace std;






template<typename T>
class Heap{ //Heap with an array, requires table doubling
	private:
	long n; //the actual number of elements in the heap
	long size;  //the size of the array. We keep doubling this as  n->size, and half it as n->size/4
	T* arr;

	public:
	Heap(long heap_size=16){    //min-heap
		size=heap_size;
		n=0;
		arr=new T[heap_size];
	}
	

	Heap(T* input_array=NULL, long num_elements=NULL){   //min-heap
		size=num_elements;
		n=num_elements;
		arr=input_array;
		make_heap();
	}

	inline long parent(long child_index){ //returns the parent's index
		return (child_index-1)/2; //floor value
	}

	inline long left_child(long parent_index){ //returns the left child's index
		return parent_index*2+1; 
	}

	inline long right_child(long parent_index){ //returns the right child's index
		return parent_index*2+2; 
	}

	private:	
	inline void shift_up(long k){
		//assuming that the rest of the array is a heap, but k (which is at the bottom level) is not, 
		//we must shift the element at index k upwards until it reaches its correct position.
		while(k!=0){
			if(arr[k]<arr[parent(k)]){ //if the new element is less than its parent, swap.
				T temp=arr[k];
				arr[k]=arr[parent(k)];
				arr[parent(k)]=temp;
			}
			else break;
			k=parent(k);
		}
	}
	
	inline void shift_down(long k){ //this is also called max-heapify (in heapsort) or min-heapify (in priority queues)
		//this function shifts the element at index k downwards, at each point replacing it with the smaller of its children (because min-heap),  
		//until it is at the correct level. Doing that ensures extract_min() will always extract the min.

		while(left_child(k)<n){		//i.e. while k is not on the bottommost layer. If it is, k's left child will be out of bounds.	  
			long index_of_lowest_child=left_child(k);
			if(right_child(k)<n && arr[left_child(k)]>arr[right_child(k)])
				index_of_lowest_child=right_child(k);
			if(arr[index_of_lowest_child] < arr[k]){  
				T temp=arr[index_of_lowest_child];
				arr[index_of_lowest_child]=arr[k];
				arr[k]=temp;
				k=index_of_lowest_child;
			}
			else break;	   	   	   	   	   	   
		}
	}

	public:
	void make_heap(){  //converts the array into a heap.
		if(n<=1) //aleady a heap
			return; 
		long i;
		for(i=parent(n-1); i>=0; i--) //start from the last element's parent, go to root
			shift_down(i);	  	  	  	  	  
	}

	inline void insert(T data){ //min heap property: arr[parent]<=arr[child]

		if(n==size){  //double the size of the heap
			T* temp_arr=new T[size*2];
			size=size*2;
			long i;
			for(i=0; i<n; i++)
				temp_arr[i]=arr[i];
			delete arr;
			arr=temp_arr;
		}
		
		arr[n]=data; //add it at the end of the heap
		shift_up(n); //we now start at the bottom-most layer and must shift the new element up, until we reach the appropriate place	
		n+=1;	
	}	 


	inline void remove_from(long index, bool doubling=true){
		//step1: swap it with the last element, and reduce the size of the array
		T temp=arr[index];
		arr[index]=arr[n-1];
		arr[n-1]=temp;
		n-=1;
		//step2: move the last element (which is now in arr[index]) up or down until we put it in its correct place, re-making the heap.
		shift_up(index);
		shift_down(index); //one of these will have no effect.

		if(doubling){
		//Reducing the size:
			if(n==size/4){//half the size of the heap
				T* temp_arr=new T[size/2];
				size=size/2;
				long i;
				for(i=0; i<n; i++)
					temp_arr[i]=arr[i];
				delete arr;
				arr=temp_arr;
				
			}
		}
	}

	void print(){
		if(n==0){
			cout<<"\n<---Empty Heap--->\n";
			return;
		}
		
		long i;
		cout<<"\n<---Heap--->\n";
		for(i=0; i<n; i++)
			cout<<arr[i]<<" ";
		cout<<"\n<---End of Heap--->\n";	
		cout<<"Number of elements: "<<n<<endl;
	}

	void print_deluxe(){
		if(n==0){
			cout<<"\n<---Empty Heap--->\n";
			return;
		}
		cout<<"\n<---Heap--->\n";
		long i=1; long j=0;
		int levels=1+int(double(log(n))/double(log(2)));
		cout<<"\nLevels:"<<levels<<endl;

		

		cout<<"\n<---End of Heap--->\n";	
		
	}
	
	inline bool isheap(){
		long i=0;
		while(left_child(i)<n){
			if ( arr[i]>arr[left_child(i)]	 ||	 (right_child(i)<n && arr[i]>arr[right_child(i)]) )
				return false;
			i+=1;
		}
		return true;
	}
	
	inline T extract_min(bool doubling=true){
		T minimum=arr[0];
		remove_from(0, doubling);
		return minimum;
	}


	long length(){
		return n;
	}
	
};




int main(){
	/*long n=100000000;
	long i;
	int *arr=new int[n];
	for(i=0; i<n; i++)
		arr[i]=( rand()+10*rand()+100*rand()+1000*rand()+10000*rand() )%n;
	
	
	
	Heap<int> *h=new Heap<int>(arr,n);
	//if(h->isheap())
	//	  h->print();
	cout<<"made";
	cin>>i;
	long start=std::clock();
	for(i=0; i<n; i++)
		h->extract_min(false);
	cout<<std::clock()-start<<" milliseconds";
	cin>>i;
*/


long n=9;
long i;
Heap<int> *h=new Heap<int>(9);
h->insert(5);
h->insert(1);
h->insert(3);
h->insert(9);
h->insert(4);
h->insert(10);
h->insert(7);
h->insert(17);
h->insert(6);
h->print();
for(i=0; i<n+1; i++){
	cout<<endl<<h->extract_min();
	if(h->isheap())
		cout<<" is heap ";
}
}




/*


template<typename T>
class HeapNode{
	public:	   
	T data;
	HeapNode<T> *parent;
	HeapNode<T> *left;
	HeapNode<T> *right;

	HeapNode(T x=NULL, HeapNode<T> *parent_node=NULL){
		parent=parent_node;
		left=NULL;
		right=NULL;
	}

};




template<typename T>
class LLHeap{	heap with pointers and nodes, no need for constant size changes
	private:
	long len;
	HeapNode<T> *top;
	
	public:
	LLHeap(){
		top=NULL;
		len=0;
	}

	void insert(T data){
		HeapNode<T> *z=new HeapNode(data);
	}
	
};
*/

