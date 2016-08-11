#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

void DFS(int** graph, int V, int startNode){
    stack<int> S;
    bool* visited = new bool[V];
    int i;
    for(i=0; i<V; i++)
        visited[i] = false;
    S.push(startNode);
    while(!S.empty()){
        int currentNode = S.top();
        S.pop();
        if(!visited[currentNode]){
            cout<<currentNode<<endl;
            visited[currentNode] = true;
            for(i=0; i<V; i++){
                if(graph[currentNode][i] != INT_MAX && !visited[i]){
                    S.push(i);
                }
            }

        }

    }
}


int main(){

    int N_DFS = 6;
	int** graph = new int*[N_DFS];
	graph[0] = new int[N_DFS]{0,		1,		 1,		   INT_MAX,		1,			INT_MAX	};
	graph[1] = new int[N_DFS]{INT_MAX,	0,		 1,		   INT_MAX,		INT_MAX,	INT_MAX	};
	graph[2] = new int[N_DFS]{INT_MAX,	1,		 0,		   INT_MAX,		INT_MAX,	INT_MAX	};
	graph[3] = new int[N_DFS]{INT_MAX, INT_MAX,  1,	 	   0,			INT_MAX,	INT_MAX	};
	graph[4] = new int[N_DFS]{INT_MAX, INT_MAX,  INT_MAX,  1,			0,			INT_MAX	};
	graph[5] = new int[N_DFS]{INT_MAX, INT_MAX,  INT_MAX,  INT_MAX,		INT_MAX,	0		};
    DFS(graph, N_DFS, 0);
    cout<<endl;
    return 0;

}
