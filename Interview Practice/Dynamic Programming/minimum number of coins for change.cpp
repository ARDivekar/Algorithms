#include<iostream>
#include<limits.h>

using namespace std;

int min(int a, int b){
    if(a<b)
        return a;
    return b;
}

template<typename T>
void printArray(T arr, int len){
    for(int i=0; i<len; i++)
        cout<<arr[i]<<"  ";
}

int minCoinsForChange(int* coins, int ref_size, int n){
    if(n==0)
        return 0;
    int* opt = new int[n+1];
    int* soln = new int[n+1];
    int i,j;

    for(i=0; i<n+1; i++)
        opt[i]=INT_MAX;


    for(j=0; j<ref_size && coins[j]<=n; j++){
        opt[coins[j]] = 1; // if a coin exits, just putting that coin is the easiest way to make change.
        soln[coins[j]] = coins[j];
        if(coins[j]==n)
            return 1;
    }

    // cout<<endl;
    // printArray(opt, n+1);
    // cout<<endl;

    for(i=1; i<=n; i++){
        for(j=0; j<ref_size && coins[j]<i; j++){ // goes through the coin array
            if(opt[i-coins[j]]+1 < opt[i]){
                opt[i] = opt[i-coins[j]]+1; //add coins[j]
                soln[i] = coins[j];
            }

        }
    }

    /* // Alternative way to do it: simpler to write, but does strictly more work:
    for(i=1; i<=n; i++){
        for(j=1; j<i; j++){
            opt[i] = min(opt[i], opt[i-j] + opt[j]);
        }
    }
    */

    i = n;
    cout<<"\nSolution: ";
    while(i>0){
        cout<<soln[i]<<"  ";
        i=i-soln[i];
    }



    cout<<"\nOPT:\n";
    printArray(opt, n+1);
    cout<<endl;

    cout<<"\nSOLN:\n";
    printArray(soln, n+1);
    cout<<endl;

    return opt[n];

}


int main(){
    int ref_size = 4; // size of coins array
    int* coins = new int[ref_size]{1,2,5,9};

    for(int i=1; i<30; i++){
        cout<<"\nMin number of coins needed to make change for "<<i<<": "<< minCoinsForChange(coins, ref_size, i);
        cout<<"\n\n";
    }


    cout<<endl;
    return 0;
}
