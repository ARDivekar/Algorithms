/*
http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including both source and destination). You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.
For example, in the following figure, what is the minimum cost path to (2, 2)?
    {1, 2, 3}
    {4, 8, 2}
    {1, 5, 3}
The path is (0, 0) –> (0, 1) –> (1, 2) –> (2, 2).
The cost of the path is 8 (1 + 2 + 2 + 3).

*/


#include<iostream>
using namespace std;

int min(int a, int b){
    return a<b? a : b;
}


const int INT_MAX = 99999999;
int shortestPathDist(int** graph, int N, int M, int dest_X, int dest_Y){
    int** opt=new int*[N];
    int i,j;
    for(i=0; i<N; i++){
        opt[i]=new int[M];
        for(j=0; j<M; j++)
            opt[i][j] = INT_MAX;
    }
    opt[0][0] = 0;


    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if(i-1>=0)
                opt[i][j] = min(opt[i][j], opt[i-1][j]);
            if(j-1>=0)
                opt[i][j] = min(opt[i][j], opt[i][j-1]);
            if(j-1>=0 && i-1>=0)
                opt[i][j] = min(opt[i][j], opt[i-1][j-1]);
            opt[i][j]+=graph[i][j];
        }
    }

    return opt[dest_X][dest_Y];

}


int main(){
    int N=3;
    int M=3;
    int** graph = new int*[N];
    graph[0] = new int[M]{1,2,3};
    graph[1] = new int[M]{4,8,2};
    graph[2] = new int[M]{1,5,3};
    int source_X = 0, source_Y = 0;
    int dest_X = N-1, dest_Y=M-1;
    cout<<"Min="<<shortestPathDist(graph, N, M, dest_X, dest_Y);
    cout<<endl;
    return 0;
}
