#include<iostream>
#include<stdlib.h>

using namespace std;

int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void doQsort(){
    int n=6;
    int* a = new int[n]{6,8,2,4,9,1};
    int i;
    qsort(a, n, sizeof(int), cmpfunc);
    for(i=0; i<n; i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}




#include<string.h> // for strcmp.

void doQsortStrings(){
    const int N = 4;
    const int len = 20;
    char strings[N][len] = {"apples", "grapes", "strawberries", "bananas"};
    qsort(strings, N, len, (int(*)(const void*, const void*))strcmp);
    int i,j;
    for(i=0; i<N; i++){
        cout<<endl;
        for(j=0; j<len && strings[i][j]!='\0'; j++)
            cout<<strings[i][j];
    }

}


int main(){
    doQsort();
    doQsortStrings();
    cout<<endl;
    return 0;
}
