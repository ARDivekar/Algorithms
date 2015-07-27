#include<iostream>
#include<list>
#include<stdlib.h>
using namespace std;

template<typename T>
class Queue{
	std::list<T> Q;
	public:
	void enqueue(T data){
		Q.push_back(data);
	}

	T dequeue(){
		T data=NULL;
		if(!Q.empty()){
			data=Q.front();
			Q.pop_front();
		}
		return data;		
	}

	bool is_empty(){
		return Q.empty();
	}

	long len(){
		return Q.size();
	}
	
	void print(){
		//cout<<"\n<---Queue--->\n";
		long len=Q.size();
		long i;
		for(i=0; i<len; i++){
			cout<<Q.front()<<"  ";
			Q.push_back(Q.front());
			Q.pop_front();
		}
		//cout<<"\n<---End of Queue--->\n";

	}

	void print_destroy(){
		//cout<<"\n<---Queue--->\n";
		while(!Q.empty()){
			cout<<Q.front()<<"  ";
			Q.pop_front();
		}
		//cout<<"\n<---End of Queue--->\n";

	}

};


template<typename T>
void RadixSort(T *input, long n){
	long i,j;
	T temp;
	Queue<int> buckets[10];
	long highest_power_of_10=1;  //assume input is an interger format
	for(i=0; i<n; i++){
		temp=input[i];
		//cout<<temp<<" ";
		buckets[temp%10].enqueue(temp);

		while(temp>=highest_power_of_10)
			highest_power_of_10*=10;  
	}
	
	//highest_power_of_10 is greater than all numbers. eg: input={1,3,5,19,7,24,85,2,75}, highest_power_of_10 = 100.

	//cout<<"\n\nHighest power of 10 = "<<highest_power_of_10<<endl;

/*Printing:  
	for(i=0; i<10; i++){
		cout<<"\nBucket "<<i<<":\t";
		//if(!buckets[i].is_empty()) 
			buckets[i].print();
	}
*/
	
	long prev_lengths[10];
	long current_pow_of_10=10;
	while(current_pow_of_10 != 10*highest_power_of_10){
		for(i=0; i<10; i++){
			prev_lengths[i]=buckets[i].len();
		}
		for(i=0; i<10; i++){
			if(!buckets[i].is_empty()){
				for(j=0; j<prev_lengths[i]; j++){
					temp=buckets[i].dequeue();
					buckets[(temp/current_pow_of_10)%10].enqueue(temp);
				}
			}
		}
/*Printing:
		cout<<"\n\n\n\tCurrent power of 10 = "<<current_pow_of_10<<endl;
		for(i=0; i<10; i++){
		cout<<"\nBucket "<<i<<":\t";
		//if(!buckets[i].is_empty()) 
			buckets[i].print();
		}
*/	  	  
		current_pow_of_10*=10;
	}
	
	
	for(i=0; i<n; i++) //copy back
		input[i]=buckets[0].dequeue();

		
}


int main(){
	long i;	
	long n=15;
	int *a=new int[n];
	for(i=0; i<n; i++){
		a[i]=rand()%(n*10);
	}

	RadixSort(a,n);

	cout<<"\n\n";
	for(i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}

