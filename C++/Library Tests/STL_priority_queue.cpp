#include <functional>
#include <queue>
#include <vector>

#ifndef IOSTREAM
#define IOSTREAM
	#include<iostream>
#endif

#ifndef STRING
#define STRING
	#include<string>
#endif

using namespace std;

void pq_test1() {
	std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
	int i;
	int n = 50;
	for (i = 0;i < n;i++)
		Q.push(rand()%(n*3));
	cout << "\n" << Q.top();
	cout << "\n" << Q.top();
	cout << "\n" << Q.top();
	for (i = 0;i < n;i++) {
		cout << "\n"<<Q.top() << " Size:"<<Q.size();
		Q.pop();
	}

}
