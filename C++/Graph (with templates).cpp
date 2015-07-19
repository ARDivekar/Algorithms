#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
using namespace std;


template<typename T>
class Node{
	T data;
	Node<T> *next;
	Node(T x=NULL, Node<T> *next_node=NULL){
		data=x;
		next=next_node;
	}
};

template<typename T>
class Graph{
	private:
	int n; //number of vertices
	int e; //number of edges
	bool directed;
	int **adj_mat;  //the numbers are the weights

	public:

	Graph(int num=NULL, bool dir=true){
		directed=dir;
		long i;
		n=num;
		e=0;
		if(num!=NULL && num>0){
			adj_mat=new int*[n];
			for(i=0; i<num; i++){
				adj_mat[i]=new int[n];
				for(long j=0; j<n; j++)
					adj_mat[i][j]=NULL;
			}
		}
	}

	void add_edge(int from, int to, int weight=1){
		if(from<n && to <n){
			adj_mat[from][to]=weight;
			if(!directed)
				adj_mat[to][from]=weight;
		}
			
	}

	void print(){
		long i;
		cout<<"\n<---Graph--->";
		for(i=0; i<n; i++){
			cout<<"\n[";
			for(long j=0; j<n; j++){
				if(j!=n-1)
					cout<<adj_mat[i][j]<<"\t";
				else cout<<adj_mat[i][j];
			}	
			cout<<"]";
		}
		cout<<endl;
	}

};	  

int main(){
	Graph<int> *g=new Graph<int>(10);
}	 
	


