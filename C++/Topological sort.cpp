#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

class DFSNode{
public:
    bool visited;
    int startTime;
    int endTime;
    DFSNode(){
        visited= false;
        startTime = -1;
        endTime = -1;
    }
};

bool existsEdge(int weight){
    if(weight!=INT_MAX)
    return true;
    return false;
}

void DFS_rec(int** graph, int V, DFSNode* nodes, int currentNode, int &currentTime, vector<int> &topological){
    int i;
    nodes[currentNode].visited = true;
    nodes[currentNode].startTime = currentTime;
    currentTime += 1;
    for(i=0; i<V; i++){
        if(existsEdge(graph[currentNode][i]) && !nodes[i].visited){
            DFS_rec(graph, V, nodes, i, currentTime, topological);
        }
    }
    nodes[currentNode].endTime = currentTime;
    currentTime += 1;
    topological.push_back(currentNode);
}


void DFS(int** graph, int V, vector<int> &topological){
    int currentTime = 1;
    int i;
    DFSNode* nodes = new DFSNode[V];
    for(i=0; i<V; i++){
        if(!nodes[i].visited)
            DFS_rec(graph, V, nodes, i, currentTime, topological);
    }
    for(i=0; i<V; i++){
        cout<<"\n"<<i<<" : "<<nodes[i].startTime<<"  "<<nodes[i].endTime;
    }
}


int main(){
    const int N_DFS = 6;
    int** graph = new int*[N_DFS];
    graph[0] = new int[N_DFS]{0,		1,		 1,		   INT_MAX,		1,			INT_MAX	};
    graph[1] = new int[N_DFS]{INT_MAX,	0,		 1,		   INT_MAX,		INT_MAX,	INT_MAX	};
    graph[2] = new int[N_DFS]{INT_MAX,	1,		 0,		   INT_MAX,		INT_MAX,	INT_MAX	};
    graph[3] = new int[N_DFS]{INT_MAX, INT_MAX,  1,	 	   0,			INT_MAX,	INT_MAX	};
    graph[4] = new int[N_DFS]{INT_MAX, INT_MAX,  INT_MAX,  1,			0,			INT_MAX	};
    graph[5] = new int[N_DFS]{INT_MAX, INT_MAX,  INT_MAX,  INT_MAX,		INT_MAX,	0		};
    vector<int> topological;
    DFS(graph, N_DFS, topological);
    cout<<"\n\nTopological: ";
    reverse(topological.begin(), topological.end());
    for(int i=0; i<topological.size(); i++){
        cout<<topological[i]<<"  ";
    }
    cout<<endl;
    return 0;
}
