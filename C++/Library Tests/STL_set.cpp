#include<set>
#include<iostream>
using namespace std;

void set_test1() {
	std::set <int> set;
	set.insert(4);
	std::set <int>::iterator search=set.find(4);
	if(search!=set.end())
		cout<<*search;
	search=set.find(3);
	if(search!=set.end())
		cout<<*search;
	else cout<<"\nnot there";
	if (set.erase(4))
		cout<<"COOL\n\n";

	set.insert(4);
	set.insert(3);
	set.insert(5);
	set.insert(4);
	set.insert(1);
	set.insert(6);
	std::set <int>::iterator i= set.begin();
	for(;i!=set.end(); i++){
		cout<<*i<<" ";
	}
	
	
}

int main() {
	int i;
	set_test1();
	cout << "\n>";
	cin >> i;
}

