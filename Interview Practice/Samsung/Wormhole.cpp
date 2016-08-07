/*
    You want to travel through space. Space is an NxN grid.
    You can move up, down, left, or right. Each movement costs you 1 point.
    Additionally, there are some wormholes. Using these wormholes, you can quickly go from point A to point B. The wormhole has a cost (some number of points) needed to travel through it.
    Wormholes are bidirectional.
    It may not always be less costly to go through the wormhole.
    You are given the starting point S, with destination D.
    You want to find the path with the least cost (points) to get from S to D.

    Example:
    0   1   2   3   4   5
0 [                 B     ]
1 [                       ]
2 [     S       A         ]
3 [                     B ]
4 [             A         ]
5 [                D      ]
Cost to go through wormhole A = 50 points
Cost to go through wormhole B = 20 points

*/
#include<iostream>
#include<stdlib.h>
using namespace std;
const int INT_MAX = int(2E31-1);

class Wormhole{
public:
    int end1_x, end1_y;
    int end2_x, end2_y;
    int cost;

    Wormhole(){
        end1_x=-1; end1_y=-1;
        end2_x=-1; end2_y=-1;
        cost = INT_MAX;
    }

    Wormhole(int end1_x, int end1_y, int end2_x, int end2_y, int cost){
        this->end1_x = end1_x;
        this->end1_y = end1_y;
        this->end2_x = end2_x;
        this->end2_y = end2_y;
        this->cost = cost;
    }

};


int numWormholes;
Wormhole* wormholes;

// Dijkstra's values:
int N;
int** graph;
int sourceIndex = 0;
int destIndex = N-1;
int* dist;
bool* visited;


int getMinDistIndex(){
    int min = INT_MAX;
    int minIndex = 0;
    for(int i=0; i<N; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}


void Dijkstra(int srcIndex){
    int i,j;
    for(i=0; i<N; i++){
        dist[i] = graph[srcIndex][i];
        visited[i] = false;
    }
    visited[srcIndex] = true;
    dist[srcIndex] = 0;

    int currentClosestNodeIndex;
    for(i=0; i<N; i++){
        currentClosestNodeIndex = getMinDistIndex();
        visited[currentClosestNodeIndex] = true;
        for(j=0; j<N; j++){
            if(graph[currentClosestNodeIndex][j] != INT_MAX
            && !visited[j]
            && dist[currentClosestNodeIndex] + graph[currentClosestNodeIndex][j] < dist[j]
            )
            dist[j] = dist[currentClosestNodeIndex] + graph[currentClosestNodeIndex][j];
        }
    }
}

void setUndirectedEdge(int from, int to, int weight){
    graph[from][to] = weight;
    graph[to][from] = weight;
}

void wormholeToDijkstra(int src_x, int src_y, int dest_x, int dest_y){
    int i,j;
    N = 2 + 2*numWormholes; // source and destination + each wormhole's ends.
    graph = new int*[N];
    for(i=0; i<N; i++){
        graph[i] = new int[N];
        for(j=0; j<N; j++)
            if(i==j)
                graph[i][j] = 0;
            else graph[i][j] = INT_MAX;
    }

    sourceIndex = 0;
    destIndex = N-1;
    const int sourceToDestDist = abs(src_x - dest_x) + abs(src_y - dest_y); // Can only go up, down, left, right. It is the same as the min diagonal distance.
    setUndirectedEdge(sourceIndex, destIndex, sourceToDestDist);

    int wormhole1_index, wormhole2_index;
    for(i=0; i<numWormholes; i++){
        // Set the distance of wormhole1 from the src and destination:
        wormhole1_index = i*2 + 1;
        setUndirectedEdge(sourceIndex, wormhole1_index, abs(src_x - wormholes[i].end1_x) + abs(src_y - wormholes[i].end1_y));
        setUndirectedEdge(destIndex, wormhole1_index, abs(dest_x - wormholes[i].end1_x) + abs(dest_y - wormholes[i].end1_y));

        // Set the distance of wormhole2 from the src and destination:
        wormhole2_index = i*2 + 2;
        setUndirectedEdge(sourceIndex, wormhole2_index, abs(src_x - wormholes[i].end2_x) + abs(src_y - wormholes[i].end2_y));
        setUndirectedEdge(destIndex, wormhole2_index, abs(dest_x - wormholes[i].end2_x) + abs(dest_y - wormholes[i].end2_y));

        setUndirectedEdge(wormhole1_index, wormhole2_index, wormholes[i].cost);
    }

}

void printGraph(){
    int i,j;
    cout<<"\nGraph:\n";
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    int src_x =  0, src_y =  0;
    int dest_x = 5, dest_y = 4;
    numWormholes = 2;
    wormholes = new Wormhole[numWormholes];
    wormholes[0] = *(new Wormhole(2,3, 4,3, 1));
    wormholes[1] = *(new Wormhole(0,4, 3,5, 1));
    wormholeToDijkstra(src_x, src_y, dest_x, dest_y);
    printGraph();
    dist = new int[N];
    visited = new bool[N];
    cout<<endl;
    cout<<"Min Dist: ";
    Dijkstra(sourceIndex);
    cout<<dist[destIndex];
    cout<<endl;
    return 0;
}
