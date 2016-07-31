#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

enum Status{
    VISITED, NOT_VISITED, IN_QUEUE
};

class Node{
public:
    int nodeIndex;
    int pathLengthFromSource;
    Status status;
    Node(int nodeIndex, int pathLengthFromSource){
        this->nodeIndex = nodeIndex;
        this->pathLengthFromSource = pathLengthFromSource;
        this->status = NOT_VISITED;
    }

    bool operator<(const Node &A){
        if(this->pathLengthFromSource > A.pathLengthFromSource) // we want a min-heap
            return true;
        return false;
    }

    bool operator>(const Node &A){
        if(this->pathLengthFromSource < A.pathLengthFromSource) // we want a min-heap
            return true;
        return false;
    }
};


int Dijkstra(int** graph, int N, int sourceIndex, int destinationIndex){
    int i,j;
    Status* nodeStatus = new Status[N];
    for(i=0; i<N; i++)
        nodeStatus[i] = NOT_VISITED;

    priority_queue<Node> q;

    // Put in all nodes directly reachable from source:
    for(i=0; i<N; i++){
        if(graph[sourceIndex][i]!=INT_MAX){
            Node* tempNode = new Node(i, 0+graph[sourceIndex][i]);
            tempNode->status = IN_QUEUE;
            q.push(*tempNode);
        }
    }

    while(!q.empty()){
        Node currentNode = q.top();
        q.pop();
        if(currentNode.nodeIndex == destinationIndex){
            return currentNode.pathLengthFromSource;
        }

        for(i=0; i<N; i++){
            if(graph[currentNode.nodeIndex][i]!=INT_MAX && nodeStatus[i]!= VISITED){ // If a path exists from current node to next, and the next node is not visited, add that node to the heap.
                Node* tempNode = new Node(i, currentNode.pathLengthFromSource + graph[currentNode.nodeIndex][i]);
                tempNode->status = IN_QUEUE;
                q.push(*tempNode);
            }
        }
        nodeStatus[currentNode.nodeIndex] = VISITED;
    }
    return INT_MAX;
}

int main(){
    int N = 5;
    int** graph = new int*[5]{
        new int[5]{0, 10, 50, INT_MAX, 10},
        new int[5]{10, 0, 10, INT_MAX, 5},
        new int[5]{50, 10, 0, 40, INT_MAX},
        new int[5]{INT_MAX, INT_MAX, 40, 0, 5},
        new int[5]{10, 5, INT_MAX, 5, 0}
    };
    int sourceIndex = 0;
    int destinationIndex = 3;
    cout<<"\nShortest distance from node "<<sourceIndex<<" to node "<<destinationIndex<<" is: "<<Dijkstra(graph, N, sourceIndex, destinationIndex);
    cout<<endl;
    return 0;
}
