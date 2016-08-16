/*
Subset sum problem is to find subset of elements whose sum adds up to a given number K. We are considering the set contains non-negative values. It is assumed that the input set is unique (no duplicates are presented).
*/

#include<iostream>
#include<vector>
using namespace std;

inBounds(int a, int b, int c){
    if(a<=b && b<=c)
        return true;
    return false;
}

template<typename T>
void print2D(T** a, int M, int N){
    cout<<endl;
    for(int j=0; j<N; j++){
        cout<<j<<"  ";
    }
    for(int i=0; i<M; i++){
        cout<<endl;
        for(int j=0; j<N; j++){
            cout<<a[i][j]<<"  ";
        }
    }
}

bool doesSubsetSumExist(vector<int> a, int K){
    int i,j;
    const int N = a.size();
    if(N==0 && K==0)
        return true;
    else if(N==1 && a[0]!=K)
        return false;

    bool** opt = new bool*[N];
    for(i=0; i<N; i++){
        opt[i] = new bool[K+1]{0};
        opt[i][0] = true;
    }
    if(inBounds(0,a[0],K))
        opt[0][a[0]] = true;

    for(i=1; i<N; i++){
        for(j=0; j<=K; j++){
            if(opt[i-1][j]==true)
                opt[i][j]=true;
        }
        for(j=0; j<=K; j++){
            if( opt[i-1][j] == true && inBounds(0, j+a[i], K)){
                // cout<<"\ni="<<i<<" j="<<j<<" a[i]="<<a[i];
                opt[i][ j+a[i] ] = true;
            }

        }
    }
    print2D(opt, N, K+1);
    return opt[N-1][K];
}


int main(){
    vector<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 6;
    doesSubsetSumExist(a, 10);
}
