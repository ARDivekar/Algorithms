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


void printMap(std::map<int, int> &myMap){
	cout<<endl;
	std::map<int, int>::iterator iter;
	for(iter = myMap.begin(); iter!=myMap.end(); iter++)
		cout << "\n" << iter->first << " : " << iter->second;
	cout<<endl;
}

void findAndEraseMap(std::map<int, int> &myMap, int key){
	if(myMap.find(key) != myMap.end())
		myMap.erase(key);
}

void map_test_1() {
	std::map<int, int> myMap;
	myMap.insert(std::map<int, int>::value_type(1, 42));
	myMap[5] = 9;
	myMap[8] = 13;
	printMap(myMap);
	findAndEraseMap(myMap, 5);
	printMap(myMap);
	findAndEraseMap(myMap, 1);
	printMap(myMap);
}


int main(){
	map_test_1();
	return 0;
}
