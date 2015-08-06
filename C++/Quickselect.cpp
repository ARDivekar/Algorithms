#include<iostream>
#include<stdlib.h>
using namespace std;

template<typename T>
void swap(T *a, long i, long j){
	T temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

template<typename T>
long Quicksort_partition(T *a, long start, long end){
	//if(start<end){
		long i=start, j=end;
		long pivpos=rand()%(end-start+1) + start;
		swap(a,start,pivpos);
		pivpos=start;
		T pivot=a[pivpos];
		while(i<j){
			i++;
			while(i<=end && a[i]<pivot) 
				i++;
			while(j>=start && a[j]>pivot) 
				j--;
			if(i<j)
				swap(a,i,j);
		}	 	 
		swap(a,j,pivpos);
	/*	  cout<<endl;
		for(i=start; i<=end; i++)
			cout<<a[i]<<" ";
	*/
		return j;
	
		
	//}	   
	//return LONG_MAX;
}

template<typename T>
long Quickselect(T *a, long start, long end, long k){
//	  cout<<"\n<---Quickselect: start="<<start<<" end="<<end<<" k="<<k<<"--->";
	if(k>=0 && k<=end-start+1){
		
		long pivpos=Quicksort_partition(a, start, end);
		if(k < pivpos-start+1)
			return Quickselect(a, start, pivpos-1, k);
		else if(k > pivpos-start+1)
			return Quickselect(a, pivpos+1, end, k-pivpos+start-1); //we pass k-pivpos because that's how many elements into the array we look
		else return pivpos;   
	}	
//	  cout<<"\nInvalid, aborting";
	return LONG_MAX;
}

template<typename T>
long Quickselect(T *a, long len, long k){
	//cout<<"\n<---Start Quickselect: len="<<len<<" k="<<k<<"--->"<<endl;
	return Quickselect(a, 0, len-1, k);
}





int main(){
	int n = 1000000, k,i;
	long *arr=new long[n]; 
	for(i=0; i<n; i++){
		arr[i]=(rand()+10*rand()+100*rand()+1000*rand()) %(n*(2+rand()%10));
	}
    
	for(k=1; k<=n; k++)
		if (k==1 || k==10 || k==100 || k==1000 || k==10000  || k==n)
	 	   cout << "\nk="<<k<<" and k'th smallest element is " << arr[Quickselect(arr, n, k)];
}






