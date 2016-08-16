/*
http://www.spoj.com/problems/FCTRL/
Given a number N, find the number of trailing zeros in N!
1 <= N <= 1000000000.
*/

#include<iostream>
#include<math.h>
using namespace std;
int numTrailingZeros(int N){
    //unsigned long long maxN = 1000000000;
    unsigned long long powOf5 = 5;
    int numZeros = 0;
    while(powOf5 < N){
        numZeros += int(N/powOf5);
        powOf5*=5;
    }
    return numZeros;
}

int main(){
    cout<<"\n"<<numTrailingZeros(3);
    cout<<"\n"<<numTrailingZeros(60);
    cout<<"\n"<<numTrailingZeros(100);
    cout<<"\n"<<numTrailingZeros(1024);
    cout<<"\n"<<numTrailingZeros(23456);
    cout<<"\n"<<numTrailingZeros(8735373);

    cout<<endl;
    return 0;
}
