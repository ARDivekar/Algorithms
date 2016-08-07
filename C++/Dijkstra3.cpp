// By Akshu from Samsung:

#include<iostream>
#include<stdlib.h>
using namespace std;

const int INT_MAX = int(2E31-1); // INT_MIN = -2147483648
int V;
int** graph;
int* dist;
bool* visited;

void printGraph(){
    int i,j;
    cout<<"\nGraph:\n";
    for(i=0; i<V; i++){
        cout<<"\n    ";
        for(j=0; j<V; j++){
            cout<<graph[i][j]<<"    ";
        }
    }
    cout<<endl;
}

void printShortestDistances(int src){
    int i;
    cout<<"\nShortest Distances:\n";
    for(i=0; i<V; i++){
        cout<<"    From "<<src<<" to "<<i<<": "<<dist[i]<<endl;
    }
    cout<<endl;
}


int minDistIndex(){
    int min_index;
    int min = INT_MAX;
    for(int i=0; i<V; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}


void dijkstras(int src_index){
    int i,j;
    for(i=0; i<V; i++){
        dist[i] = graph[src_index][i];
        visited[i] = false;
    }
    visited[src_index]=true;

    int closetNodeIndex;
    for(i=0; i<V; i++){
        closetNodeIndex = minDistIndex();
        visited[closetNodeIndex] = true;
        for(j=0; j<V; j++){
            if( graph[closetNodeIndex][j]!=INT_MAX  // If there exists a path
             && !visited[j] // node adjacent to closetNodeIndex is not visited
             && dist[closetNodeIndex] + graph[closetNodeIndex][j] < dist[j]
            ) dist[j] = dist[closetNodeIndex] + graph[closetNodeIndex][j];    // update shortest distance to j.
        }
    }
}



int main(){
    V = 5;
    graph = new int*[V];
    graph[0] = new int[V]{0, 3, 5, 7, INT_MAX};
    graph[1] = new int[V]{3, 0, 1, 2, INT_MAX};
    graph[2] = new int[V]{5, 1, 0, INT_MAX, INT_MAX};
    graph[3] = new int[V]{7, 2, INT_MAX, 0, 4};
    graph[4] = new int[V]{INT_MAX, INT_MAX, INT_MAX, 4, 0};
    dist = new int[V];
    visited = new bool[V];
    // cout<<INT_MAX<<endl;
    int i;
    int src = 2;
    printGraph();
    dijkstras(src);
    printShortestDistances(src);
    return 0;
}
