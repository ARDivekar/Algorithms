#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

#include<limits.h>
#include<stdio.h>

using namespace std;


int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

template<typename T>
void printArray(T* arr, int len, string spacer="  "){
    for(int i=0; i<len; i++){
        cout<<arr[i]<<spacer;
    }
}

template<typename T>
void print2DArray(T* arr, int rows, int cols, string linespacer="\n", string spacer="  "){
    for(int i=0; i<rows; i++){
        cout<<linespacer;
        for(int j=0; j<cols; j++)
            cout<<arr[i][j]<<spacer;
    }
}


int rodCutting(int** ref, int ref_size, int n){
    cout<<endl;
    print2DArray(ref, ref_size, 2);
    cout<<endl;
    int* opt = new int[n+1];
    int i,j;
    for(i=0; i<n+1; i++)
        opt[i]=0;
    cout<<endl;
    printArray(opt, n+1, "\t");
    cout<<endl;

    for(j=0; j<ref_size; j++)
        opt[ref[j][0]] = ref[j][1];

    cout<<endl;
    printArray(opt, n+1, "\t");
    cout<<endl;

    for(i=1; i<=n; i++){
        int maxProfit = -1;
        for(j=1; j<=i; j++)
            maxProfit = max(maxProfit, opt[i-j]+opt[j]);
        opt[i]=maxProfit;
    }

    cout<<"\nOpt table:\n";
    for(i=0; i<n+1; i++)
        cout<<i<<"\t\t";
    cout<<endl;
    printArray(opt, n+1, "\t\t");
    cout<<endl;
    return opt[n];
}


int main(){
    int ref_size = 9;
    int** ref = new int*[ref_size];
    ref[0] = new int[2]{1,1};
    ref[1] = new int[2]{2,5};
    ref[2] = new int[2]{3,8};
    ref[3] = new int[2]{4,9};
    ref[4] = new int[2]{5,10};
    ref[5] = new int[2]{6,17};
    ref[6] = new int[2]{7,17};
    ref[7] = new int[2]{8,20};
    ref[8] = new int[2]{9,13};

    int n=100;  //compare to GeeksForGeeks solution with n=ref_size , via http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
    cout<<"\nMax Profit for (size="<<n<<"): "<<rodCutting(ref, ref_size, n);


    cout<<endl;
    return 0;
}
