#include<iostream>
using namespace std;

long max(long a, long b){
	return a>b?a:b;
}


long LIS_iter(int *a, long len, bool printing=false){
	long *LIS_max_arr=new long[len];  //LIS_max_arr[i] = optimal solution upto i
	long i,j;
	for(i=0; i<len; i++)
		LIS_max_arr[i]=1;

	for ( i = 1; i < len; i++ )
	    for ( j = 0; j < i; j++ )
			if ( a[j]<a[i] && LIS_max_arr[i] < LIS_max_arr[j]+1)
	            LIS_max_arr[i] = LIS_max_arr[j] + 1;
		
	
	long maximum=1;
	for(i=0; i<len; i++)
		maximum=max(maximum, LIS_max_arr[i]);	   

	
	if (printing){
		cout<<"\nLIS_arr: ";
		for(i=0; i<len; i++)
			cout<<LIS_max_arr[i]<<" ";
	
		cout<<"\nSequence (in reverse): ";
		long top=maximum;
		for(i=len-1; i>=0; i--){
			if(LIS_max_arr[i]==top){
				cout<<a[i]<<" ";
				top--;
			}
		}
	}
	

	return maximum;
}











long LIS_including(int *a, long i, long *LIS_max_arr){ //we find LIS of a[0...i], with a[i] at the end of the subsequence.
      if (i==0) 
            return 1; 
      long lis_including_i=1; //at any given point, holds the length of the longest increasing subsequence with a[i] at the end.
      for(long j=0; j < i; j++){
            if (a[j] < a[i]){
                  long lis_including_j = LIS_max_arr[j];
                  lis_including_i = max( lis_including_i, lis_including_j +1 );  //updates if we find a longer increasing subsequence with a[i] at the end. 
            }
      }
      //cout<<"\ni="<<i<<" lis_including_i="<< lis_including_i;
      return lis_including_i;
		
}



long LIS_rec(int *a, long len, bool printing=false){
	long *LIS_max_arr=new long[len];  //LIS_max_arr[i] = optimal solution upto i
	long i;
	for(i=0; i<len; i++)
		LIS_max_arr[i]=LIS_including(a,i, LIS_max_arr);

	long maximum=1;
	for(i=0; i<len; i++)
		maximum=max(maximum, LIS_max_arr[i]);	   


	
	if (printing){
		cout<<"\nLIS_arr: ";
		for(i=0; i<len; i++)
			cout<<LIS_max_arr[i]<<" ";
	
		cout<<"\nSequence (in reverse): ";
		long top=maximum;
		for(i=len-1; i>=0; i--){
			if(LIS_max_arr[i]==top){
				cout<<a[i]<<" ";
				top--;
			}
		}
	}

	return maximum;
		
}


int main(){
	while(true){
		long n;
		cout<<"\nEnter n:\n>";
		cin>>n;
		long x=4;
		cout<<"\nEnter x:\n>";
		cin>>x;
		int *a=new int[n];
		long i;
		for(i=0; i<n; i++){
			a[i]=rand()%(n*x);
			cout<<a[i]<<" ";
		}
		
		long iter=LIS_iter(a,n,true);
		cout<<"\n\nLIS_iter: "<<iter;
		long rec=LIS_rec(a,n,true);
		cout<<"\n\nLIS_rec: "<<rec;
	}	 	 
	return 1;
}

