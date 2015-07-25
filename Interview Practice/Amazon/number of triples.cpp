/*Q: 
Given an array of numbers find all such triplets that satisfy the given condition.

Condition: a[i] < a[j] < a[k] where i < j < k.

*/
#include<stdlib.h>
#include<set>
#include<iostream>
using namespace std;

template<typename T>
class Node{
	public:
	T first;
	T second;
	T third;
	Node(T input_first, T input_second, T input_third){
		first=input_first;
		second=input_second;
		third=input_third;
	}

	bool operator==(const Node<T> &A) const{
		if(A.first==first && A.second==second && A.third==third)
			return true;
		else return false;
	}

	bool operator<(const Node<T> &A) const{
		if(A.first<first && A.second<second && A.third<third)
			return true;
		else return false;
	}

	void operator<<(const Node<T> &A) const{
		cout<<"("<<first<<","<<second<<","<<third<<")";
	}
	
};

//template<typename T>
void triples(int *A, long size){
	std::set< Node<int> > trips;
	std::set< Node<int> >::iterator iter;
	long i;
	for(i=0; i<size-2; i++){
		if(A[i]<A[i+1]<A[i+2])
			trips.insert(*(new Node<int>(A[i],A[i+1],A[i+2])));
	}	 

	
	for(iter=trips.begin();iter!=trips.end(); iter++)
		cout<<"("<<(*iter).first<<","<<(*iter).second<<","<<(*iter).third<<") ";
}


int main(){
	int n=10;
	int *a=new int[n];
	long i;
	for(i=0; i<n; i++){
		a[i]=rand()%n*2;
		cout<<a[i]<<" ";
	}
	triples(a, n);
}

