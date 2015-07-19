#include<iostream>
using namespace std;


class Edge{
	public:
	long from;
	long to;
	int total_weight;
	
	Edge(long from_index=-1, long to_index=-1, int w=NULL){
		from=from_index;
		to=to_index;
		total_weight=w;
	}	 
	
	void print(){
		cout<<"(from:"<<from<<", to:"<<to<<", weight:"<<total_weight<<")   ";
	}

	bool operator<(const Edge& x){  //if a<b
		if(total_weight < x.total_weight){
			//cout<<"\nTrue,"<<total_weight<<"<"<< x.total_weight;
			return true;
		}
		else{
			//cout<<"\nFalse,"<<total_weight<<">="<< x.total_weight;
			return false;
		}
	}

	bool operator>(const Edge& x){
		if(total_weight > x.total_weight){
			//cout<<"\nTrue,"<<total_weight<<">"<< x.total_weight;
			return true;
		}
		else{
			//cout<<"\nFalse,"<<total_weight<<"<="<< x.total_weight;
			return false;
		}
	}

	bool operator==(const Edge& x){
		if(total_weight == x.total_weight)
			return true;
		else return false;
	}
};


template<typename T>
class Heap{
	private:
	long n;   //the number of elements in the heap
	long arr_size;  //the size of the array
	T *a;  //the array we use as a heap

	public:
	Heap(long size=16){
		if(size<1)
			size=16;
		arr_size=size;
		n=0;
		a=new T[arr_size];	  	  
	}

	private:	
	
	void swap(T *arr, long i, long j){
		T temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	
	long parent(long child_index){
		return (child_index-1)/2;
	}

	long left_child(long parent_index){
		return parent_index*2 +1;
	}

	long right_child(long parent_index){
		return parent_index*2 +2;
	}
	
	void shift_up(long k){	 // k is the index of the element we want to shift upwards
		while(k!=0){
			if(a[k]<a[parent(k)]){
				swap(a,k,parent(k));
				k=parent(k);
			}	 	 	 
			else return;
		}
	}

	void shift_down(long k){
		while(left_child(k)<n){
			long index_of_smallest_child=left_child(k);
			if(right_child(k)<n  && a[right_child(k)]<a[left_child(k)])
				index_of_smallest_child=right_child(k);
	
			if(a[index_of_smallest_child] < a[k]){
				swap(a,k,index_of_smallest_child);
				k=index_of_smallest_child;
			}
			else return;  //k is at the correct level	 
		}
	}

	public:
	void make_heap(){
		long i;
		for(i=parent(n-1); i>=0; i--)
			shift_down(i);
	}
	
	
	void insert(T data){
		if(n==arr_size){   //doubling
			T *temp_arr=new T[arr_size*2];
			arr_size=arr_size*2;
			long i;
			for(i=0; i<n; i++){
				temp_arr[i]=a[i];
			}
			delete a;
			a=temp_arr;
		}
		
		a[n]=data;
		shift_up(n);
		n+=1;
	}


	void remove_from(long index, bool halving=true){
		if(n==0 || index<0)
			return;
		swap(a,index,n-1);
		n-=1;
		shift_up(index);
		shift_down(index);
		

		if(n==arr_size/4 && halving){
			T *temp_arr=new T[arr_size/4];
			arr_size=arr_size/4;
			long i;
			for(i=0; i<n; i++){
				temp_arr[i]=a[i];
			}
			delete a;
			a=temp_arr;
		}  
	}
	bool is_heap(){
		long i;
		for(i=0; left_child(i)<n; i++){
			if(a[i]>a[left_child(i)] || (right_child(i)<n && a[i]>a[right_child(i)]))
				return false;
		}
		return true;
	}

	T extract_min(){
		if(n==0){
			print();
			return -1;
		}
		T minimum=a[0];
		remove_from(0);
		return minimum;
	}

	void print(){
		if(n==0){
			cout<<"\n<---Heap Empty--->\n";
			return;
		}
		cout<<"\n<---Heap--->\n";
		long i;
		for(i=0; i<n; i++){
			//if (std::is_same<T, Edge>::value)
				cout<<"(from:"<<a[i].from<<", to:"<<a[i].to<<", weight:"<<a[i].total_weight<<")   ";
			//else cout<<a[i]<<"  ";
			
		}
		cout<<"\n<---End of Heap--->\n";
		cout<<"\nNumber of elements: "<<n<<endl;

	}
	
	long length(){	
		return n;
	}

};



class Graph{
	private:
	long n; //number of nodes
	long e; //number of edges
	int **a; //our graph. Weights are the numbers
	
	public:
	Graph(long size, int start_weight=NULL){
		n=size;
		e=0;
		a=new int* [n];
		long i;
		for(i=0; i<n; i++){
			a[i]=new int[n];
			for(long j=0; j<n; j++)
				a[i][j]=start_weight;
		}
	}

	void add_edge(long from, long to, long weight=1){
		a[from][to]=weight;
	}



	long Djikstras(long from, long to){
		int *shortest_dists=new int[n];	   	   
		long i,j;
		for(i=0; i<n; i++)
			shortest_dists[i]=-1; //-1 is the infinity value; it's safe because Djikstras doesn't work with -ve weights
		shortest_dists[from]=0;  //shortest distance of from from from is 0. Haha.

		Heap<Edge>* h=new Heap<Edge>;

		cout<<"\nInitial heaping...\n";
		for(i=0; i<n; i++){
			if(a[from][i]!=NULL)
				h->insert(*(new Edge(from,i,a[from][i])));
		}

		Edge *e;
		while(shortest_dists[to]==-1){
			e=&h->extract_min();
			while(shortest_dists[e->to] != -1){
				if(h->length()==0) //we've emptied our options and must quit.
					return shortest_dists[to];
				e=&h->extract_min();
			}
			//now, e is from a node we have seen, to an unseen node. So, we must add all the total weights to the heap.
			long to_insert=e->to;  //the index of the node whose neighbours we have to insert into the heap
			//we no longer care about e->from

			shortest_dists[to_insert]=e->total_weight;
			//we must now insert the total distances into the heap.
			for(i=0; i<n; i++){
				if(a[to_insert][i]!=NULL && shortest_dists[i]==-1)
					h->insert(*(new Edge(to_insert, i, shortest_dists[to_insert]+a[to_insert][i])));
			
			}	 
			
		}
		return shortest_dists[to];

		
	}







	void print(){
		long i,j;
		cout<<"\n<---Graph--->";
		for(i=0; i<n; i++){	
			cout<<"\n[";
			for(j=0; j<n-1; j++){	
				cout<<a[i][j]<<"\t";	
				
			}
			cout<<a[i][j]<<"]";	    
		}
		
	}

};


int main(){

	Graph *g=new Graph(5);
	g->add_edge(0,1,10);
	g->add_edge(0,2,10);
	g->add_edge(1,4,25);
	g->add_edge(2,3,5);
	g->add_edge(2,4,20);
	g->add_edge(3,1,30);
	g->add_edge(3,4,10);
	g->add_edge(4,1,30);
	
	cout<<g->Djikstras(0,3);
	
}

