
// given a sorted array, this returns either the index of the element we want, or, if it not found, the indices where it should go.
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

class index_pair{
	public:
	bool is_pair;
	int first;
	int second;
	index_pair(int first_, int second_=-1){
		if(second_ != -1)
			is_pair=true;
		else is_pair=false;
		first=first_;
		second=second_;

	}
};

template<typename T>
index_pair binary_almost_search(T *a, long len, T data){
	long low=0;
	long high=len;
	long mid;
	while(low<=high){
		mid=(low+high)/2;
		cout<<"\nmid= "<<mid<<"; low="<<low<<"; high="<<high<<" ; a[mid]="<<a[mid];
		if(a[mid]==data){
			cout<<"\nFound element: "<<data<<" at index: "<<mid;
			return *(new index_pair(mid));
		}
		else if(data < a[mid])
			high=mid-1;
		else low=mid+1;
		
	}
	cout<<"\n"<<data<<" goes between elements: "<<a[high]<<" and "<<a[low]<<", at indices: "<<high<<" and "<<low<<" respectively.";
	return *(new index_pair(high,low));


}

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int main(){
	long n=30;
	int *a=new int[n];
	long i;
	for(i=0; i<n; i++){
		a[i]=rand()%(n*10);
		cout<<i<<"\t";
		//cout<<a[i]<<" ";
	}

	qsort(a,n, sizeof(int), compare_ints);
	cout<<endl;
	for(i=0; i<n; i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	int random_integer=rand()%(n*10);
	binary_almost_search(a, n, random_integer);
	

		
		
		

}

