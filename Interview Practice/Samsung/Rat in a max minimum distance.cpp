/*
You are given an mxn grid, where(0, 0) refers top most left position and (m - 1, n - 1) the bottom most right.
The grid is filled with ones.
All positions in the grid that are blocked are filled with zeros.
You are given this grid and are assured that there exists atleast one path from (0,0) to (m-1, n-1).
Find the minimum distance of the path from (0,0) to (m-1, n-1) given that you are allowed to move only vertically, horizontally and diagonally
*/

// Solution: use BFS
#include<iostream>
#include<stdlib.h>
using namespace std;

class Point {
public:
	int x, y, distanceFromSource;
	Point(int x = -1, int y = -1, int distanceFromSource=INT_MAX) {
		this->x = x;
		this->y = y;
		this->distanceFromSource = distanceFromSource;
	}
};


class PointQueue {
public:
	int size;
	int head;
	int tail;
	Point* q;
	PointQueue(int size) {
		head = 0;
		tail = -1;
		this->size = size;
		q = new Point[size];
	}

	void enqueue(Point inputPoint) {
		if (tail >= size)
			return;
		tail += 1;
		q[tail].x = inputPoint.x;
		q[tail].y = inputPoint.y;
		q[tail].distanceFromSource = inputPoint.distanceFromSource;
	}

	Point pop() {
		if (isEmpty())
			return NULL;
		Point temp = q[head];
		head += 1;
		return temp;

	}

	bool isEmpty() {
		if (tail < head)
			return true;
		return false;
	}

	void print(){
		int i;
		cout << endl<<"\nQueue:\n";
		for (i = head; i <= tail; i++) {
			cout<<"("<<q[i].x<<", "<< q[i].y<<", d="<< q[i].distanceFromSource<<")    ";
		}
		cout << endl;
	}
};

bool inBounds(int lower, int index, int upper){
	if (lower <= index && index <= upper)
		return true;
	return false;
}


int M_rat, N_rat;
bool** visited;
int** grid;

int minDistUsingBFS() {
	int i, j, d;
	int M = M_rat;
	int N = N_rat;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			visited[i][j] = false;

	PointQueue q((M+1)*(N+1));
	q.enqueue(*(new Point(0, 0, 0)));

	Point current;
	while (!q.isEmpty()) {
		current = q.pop();
		i = current.x;
		j = current.y;
		d = current.distanceFromSource;
		//cout << "\n(i,j,dist) = ("<<i<<","<<j<<","<<d<<")";
		if (visited[i][j]) {
			//cout << "; visited";
			continue;
		}
		visited[i][j] = true;
		// Go systematically:
		if (i == M - 1 && j == N - 1) {
			//cout << "\nDONE\n";
			return d;
		}

		// Top left:
		if (inBounds(0, i - 1, M - 1) &&
			inBounds(0, j - 1, N - 1)
			&&  grid[i - 1][j - 1] == 1 &&
			!visited[i - 1][j - 1])
			q.enqueue(*(new Point(i - 1, j - 1, d + 1)));
		// Top:
		if (inBounds(0, i - 1, M - 1) &&
			inBounds(0, j, N - 1)
			&&  grid[i - 1][j] == 1 &&
			!visited[i - 1][j])
			q.enqueue(*(new Point(i - 1, j, d + 1)));
		// Top right:
		if (inBounds(0, i - 1, M - 1) &&
			inBounds(0, j + 1, N - 1)
			&&  grid[i - 1][j + 1] == 1 &&
			!visited[i - 1][j + 1])
			q.enqueue(*(new Point(i - 1, j+1, d + 1)));
		// Right:
		if (inBounds(0, i, M - 1) &&
			inBounds(0, j + 1, N - 1)
			&&  grid[i][j + 1] == 1 &&
			!visited[i][j + 1])
			q.enqueue(*(new Point(i, j + 1, d + 1)));
		// Bottom right:
		if (inBounds(0, i + 1, M - 1) &&
			inBounds(0, j + 1, N - 1)
			&&  grid[i + 1][j + 1] == 1 &&
			!visited[i + 1][j + 1])
			q.enqueue(*(new Point(i + 1, j + 1, d + 1)));
		// Bottom:
		if (inBounds(0, i + 1, M - 1) &&
			inBounds(0, j, N - 1)
			&&  grid[i + 1][j] == 1 &&
			!visited[i + 1][j])
			q.enqueue(*(new Point(i + 1, j, d + 1)));
		// Bottom left:
		if (inBounds(0, i + 1, M - 1) &&
			inBounds(0, j - 1, N - 1)
			&&  grid[i + 1][j - 1] == 1 &&
			!visited[i + 1][j - 1])
			q.enqueue(*(new Point(i + 1, j - 1, d + 1)));
		// Left:
		if (inBounds(0, i, M - 1) &&
			inBounds(0, j - 1, N - 1)
			&&  grid[i][j - 1] == 1 &&
			!visited[i][j - 1])
			q.enqueue(*(new Point(i, j - 1, d + 1)));

		//q.print();
	}

	cout << "\nCould not find anything\n";
	return INT_MAX;
}

int main() {
	int i=0, j=0;

	M_rat = 4;
	N_rat = 5;
	int M = M_rat;
	int N = N_rat;
	grid   = new int*[M];
	grid[0] = new int[N]{1, 0, 1, 0, 1};
	grid[1] = new int[N]{1, 1, 0, 1, 1};
	grid[2] = new int[N]{0, 1, 1, 0, 1};
	grid[3] = new int[N]{0, 1, 1, 1, 1};


	visited = new bool*[M];
	for (i = 0; i < M; i++)
		visited[i] = new bool[N];
	cout << minDistUsingBFS();
	cout << endl;
	return 0;

}
