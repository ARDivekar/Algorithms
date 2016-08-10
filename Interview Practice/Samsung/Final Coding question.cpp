/*
A function f(n) = a*n + b*n*(floor(log(n)/log(2))) + c*n*n*n exists.
At a particular value f(n)=k; given k, a, b, c, find n.
Limits:
n < 2^63-1
0 < a, b < 100
0 <= c < 100
If for a given value of `k` no `n` value exists, then return 0.
*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

/*
unsigned long long pow(int a, int x){
unsigned long long val = 1;
for(int i=0; i<x; i++)
val = val*x;
return val;
}
*/

unsigned long long logToBase2Floor(unsigned long long n){
    return (unsigned long long)(double(log(n))/double(log(2)));
}

#define f(n, a, b, c) (a*n + b*n*(logToBase2Floor(n)) + c*n*n*n)

unsigned long long findNByBinarySearch(unsigned long long k, unsigned long long a, unsigned long long b, unsigned long long c){
    unsigned long long low = 1;
    unsigned long long high = (unsigned long long)(7E17); //empirically derived constant
    if(c!=0)
        high = (2ULL << 21);
    else if(a==99 && b==99)
        high = 2E15;

    unsigned long long n;
    while(low<=high){
        n = (low+high)/2;
        if(f(n,a,b,c) == k)
        return n;
        else if(f(n,a,b,c) < k)
        low = n+1;
        else high = n-1;
    }
    return 0;
}

void findMaxK(){
    unsigned long long n,a,b,c,k,maxK,i, prev;
    maxK = pow(2,63)+(pow(2,63)-1);
    a=1;
    b=1;
    c=0;
    prev = 0;
    k = 1;
    for(i=1; i<maxK && f(i,a,b,c)<maxK && prev<k && k!=0 && i!=0; i*=2){
        cout<<"\n\n";
        cout<<"maxK = "<<maxK<<endl;
        cout<<"   k = "<<f(i,a,b,c)<<"  i="<<i<<endl;
    }
    prev = 0;
    k = 1;
    for(i=461168018427387904; i<maxK && f(i,a,b,c)<maxK && prev<k; i+=1E15){
        cout<<"\n\n";
        cout<<"maxK = "<<maxK<<endl;
        prev = k;
        k = f(i,a,b,c);
        cout<<"   k = "<<k<<"  i="<<i<<endl;
    }
}

int main(){
    unsigned long long n, a, b, c;
    n = 1234567890;
    a = 99;
    b = 99;
    c = 0;
    cout<<"\nn="<<n<<"  a="<<a<<"  b="<<b<<"  c="<<c<<"    k = "<<f(n, a, b, c);
    cout<<"\nANSWER: "<<findNByBinarySearch(f(n, a, b, c), a, b, c)<<endl;

    n = 1E15;
    cout<<"\nn="<<n<<"  a="<<a<<"  b="<<b<<"  c="<<c<<"    k = "<<f(n, a, b, c);
    cout<<"\nANSWER: "<<findNByBinarySearch(f(n, a, b, c), a, b, c)<<endl;

    c = 99;
    n = 1000;
    cout<<"\nn="<<n<<"  a="<<a<<"  b="<<b<<"  c="<<c<<"    k = "<<f(n, a, b, c);
    cout<<"\nANSWER: "<<findNByBinarySearch(f(n, a, b, c), a, b, c)<<endl;

    // findMaxK();
    return 0;
}
