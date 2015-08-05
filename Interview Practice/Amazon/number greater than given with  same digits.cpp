#include<iostream>
using namespace std;


long number_just_greater(long num){
	if(num<10)
		return num;	   

	//num is greater than 10 now		
	short smaller_digit=num%10;	//first digit from right
	short larger_digit=(num/10)%10;	//second digit from right
	if(num/100 == 0)  //if it's a two-digit number;
		if(larger_digit < smaller_digit)
			return 10*smaller_digit+larger_digit;
		else return num;

	//num is greater than 100 now
	long i;
	short sort[10];  //used for counting-sort of digits
	for(i=0; i<10; i++)
		sort[i]=0;
	long pow_of_10=10;
	short smallest_digit_greater_than_reverse;


	while(pow_of_10<=num){
		//cout<<"\n"<<num<<" "<<pow_of_10<<endl;
		//cout<<"\nPOW_OF_10 = "<<pow_of_10<<"\n";
		smaller_digit=(num*10/pow_of_10)%10;
		larger_digit=(num/pow_of_10)%10;
		//cout<<larger_digit<<" "<<smaller_digit;
		
		if(smaller_digit<=larger_digit){
			sort[smaller_digit]+=1;
		}
		else{
			//cout<<"\n\tReversal detected!";
			sort[smaller_digit]+=1;
			for(i=larger_digit+1; i<10; i++){
				if(sort[i]>0){
					smallest_digit_greater_than_reverse=i;
					//cout<<"\n\tsmallest_digit_greater_than_reverse="<<smallest_digit_greater_than_reverse;
					sort[i]-=1;
					break;
				}
			}
			sort[larger_digit]+=1;
			//cout<<"\n\tNUM="<<num;
			num=num/(10*pow_of_10);
			num=num*(10*pow_of_10);
			//cout<<"\n\tNUM="<<num;
			//the rightmost few digits, including those of the larger & smaller of reversal, have been cleared
			num+=pow_of_10*smallest_digit_greater_than_reverse;
			i=0;
			while(i!=10){
				while(sort[i]>0){
					pow_of_10/=10;
					num+=pow_of_10*i;
					sort[i]-=1;
					//cout<<"\n\tNUM="<<num;
				}
				i++;
			}
			break;
			
			
		}

		/*
		cout<<"\nSort[]:";
		for(i=0; i<10; i++)
			cout<<"\n"<<i<<" : "<<sort[i];
		cout<<endl<<endl;
		*/
			
		pow_of_10*=10;
	}

	return num;	   


}


int main(){
	long num;
	cout<<"Enter a number:\n>";
	cin>>num;
	cout<<"\nSmallest greater number="<<number_just_greater(num);

}

