#include<iostream>
using namespace std;

int max(int a, int b){
	if(a>b)
		return a;
	else 
		return b;
}

int best_buy_sell_pair(int *a, long len){
	if(len==1)
		return a[0];
	if(len==2)
		return max(0, a[1]-a[0]);
	int min_so_far=a[0], min_so_far_index=0;
	int best_so_far=0, best_so_far_min_index=-1, best_so_far_max_index=-1;
	for(long i=1; i<len; i++){
		if(a[i]<min_so_far){
			min_so_far=a[i];
			min_so_far_index=i;
		}	 	 
		if(a[i]-min_so_far>best_so_far){
			best_so_far=a[i]-min_so_far;
			best_so_far_min_index=min_so_far_index;
			best_so_far_max_index=i;
		}
	}
	if (best_so_far==0)
		cout<<"\nNo best buy-sell pair, price keeps reducing";
	else{
		cout<<"\nMin: "<<a[best_so_far_min_index]<<" at index: "<<best_so_far_min_index;
		cout<<"\nMax: "<<a[best_so_far_max_index]<<" at index: "<<best_so_far_max_index;
	}
	return best_so_far;   //returns the max profit to be made
}

int main(){
	int n=30;
	long i;
	int *a=new int[n];
	cout<<endl;
	for(i=0; i<n; i++){
		a[i]=1+rand()%(n*(10+rand()%10));
		cout<<a[i]<<" ";
	}
	cout<<endl<<best_buy_sell_pair(a,n);
	

}

