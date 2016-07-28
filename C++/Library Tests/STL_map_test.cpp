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
	std::map<int, int> myMap;
	myMap.insert(std::map<int, int>::value_type(1, 42));

	cout<<endl;
	std::map<int, int>::iterator iter;
	for(iter = myMap.begin(); iter!=myMap.end(); iter++)
		cout << "\n" << iter->first << " : " << iter->second;
	cout<<endl;
}


int main(){
	map_test_1();
	return 0;
}
