#include<map>
#ifndef IOSTREAM
#define IOSTREAM
	#include<iostream>
#endif
#ifndef STRING
#define STRING
	#include<string>
#endif

using namespace std;

void map_test_1() {
	std::map<int, int> map;
	map.insert({ 1,3 });
	for (auto iter : map)
		cout << "\n" << iter.first << ":" << iter.second;
	map.insert({ 1,5 });
}
