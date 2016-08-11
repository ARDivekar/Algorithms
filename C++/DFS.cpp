#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;

int N_DFS;
int **graph;
bool* visited;


void DFS_rec(int currentNode) {
	cout << currentNode << "  ";
	visited[currentNode] = true;
	int i;
	for (i = 0; i < N_DFS; i++) {
		if (i!=currentNode &&
			graph[currentNode][i] != INT_MAX &&
			visited[i] == false) {
				cout << "\nGoing to node " << i << " now, bye!\n";
				DFS_rec(i);
		}
	}
}

void printGraph() {
	cout <<"\nGraph:\n";
	int i, j;
	for (i = 0; i < N_DFS; i++) {
		cout << endl;
		for (j = 0; j < N_DFS; j++) {
			cout << graph[i][j] << "  ";
		}
	}
	cout << endl;
}

void DFS() {
	printGraph();
	cout << endl;
	for (int i = 0; i < N_DFS; i++)
		visited[i] = false;
	cout << endl;
	for (int i = 0; i < N_DFS; i++)
		if(visited[i] == false)
			DFS_rec(i);
	cout << endl;
}

int main() {
	N_DFS = 6;
	graph = new int*[N_DFS];
	graph[0] = new int[N_DFS]{0,		1,		 1,		   INT_MAX,		1,			INT_MAX	};
	graph[1] = new int[N_DFS]{INT_MAX,	0,		 1,		   INT_MAX,		INT_MAX,	INT_MAX	};
	graph[2] = new int[N_DFS]{INT_MAX,	1,		 0,		   INT_MAX,		INT_MAX,	INT_MAX	};
	graph[3] = new int[N_DFS]{INT_MAX, INT_MAX,  1,	 	   0,			INT_MAX,	INT_MAX	};
	graph[4] = new int[N_DFS]{INT_MAX, INT_MAX,  INT_MAX,  1,			0,			INT_MAX	};
	graph[5] = new int[N_DFS]{INT_MAX, INT_MAX,  INT_MAX,  INT_MAX,		INT_MAX,	0		};
	visited = new bool[N_DFS];
	DFS();
	cout << endl;
	return 0;
}
