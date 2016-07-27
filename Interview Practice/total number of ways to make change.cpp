#include<iostream>
using namespace std;

template<typename T>
void printArray(T arr, int len){
    for(int i=0; i<len; i++)
        cout<<arr[i]<<"  ";
}

int totalNumWaysToMakeChange(int* coins, int ref_size, int n){
    int i,j;
    int* opt = new int[n+1];
    for(i=1; i<=n; i++)
        opt[i] = 0;
    opt[0] = 1;

    for(i=1; i<=n; i++){
        for(j=0; j<ref_size; j++){
            if(i-coins[j] >= 0)
                opt[i] += opt[i-coins[j]];
        }
    }

    cout<<"\nOPT:\n";
    printArray(opt, n+1);
    cout<<endl;

    return opt[n];
}


int main(){
    int ref_size = 4;
    int* ref = new int[ref_size]{1, 2, 4, 5};
    int n = 10;
    cout<<"\nTotal number of ways to make change:\n"<<totalNumWaysToMakeChange(ref, ref_size, n);
    cout<<endl;
    return 0;
}
