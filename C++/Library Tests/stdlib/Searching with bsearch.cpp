#include<iostream>
#include<stdlib.h>
using namespace std;

int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void doBsearch(){
    int a[] = {1, 3, 5, 6, 7, 8, 9, 15, 20, 26};
    int N = sizeof(a)/sizeof(int);
    int key = 3;
    int* mem_location = (int*) bsearch(&key, a, N, sizeof(int), cmpfunc);
    if(mem_location){
        cout<<(*mem_location)<<" found at location "<<mem_location;
    }
    else cout<<"not found.";
}

int main(){
    doBsearch();
    cout<<endl;
    return 0;
}
