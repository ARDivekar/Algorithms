#include<unordered_map>  //only allowed in C++ 11 and above
#include<iostream>
#include<string>

using namespace std;

void un_map_test1() {
	std::unordered_map<int, int>map;
	long i;
	for (i = 10; i > -60; i--) {
		map[i] = -i;
	}
	cout << "\n\n\nUSING ERASE:";
	map.erase(-5);

	cout << "\nUsed " << map.size() << " of " << map.bucket_count();

	cout << "\nTrying to access map[-5] which we have now deleted : ";
	if (map[-5] == NULL)
		cout << "It is NULL";
	cout << "\nNote: now that we have tried to access map[-5], it exists: ";
	cout << "\nUsed " << map.size() << " of " << map.bucket_count();

	cout << "\nWe don't want this to happen. Let's erase it again:";
	map.erase(-5);
	cout << "\nDone.";
	cout << "\nUsed " << map.size() << " of " << map.bucket_count();

	cout << "\nNow, let's use map.find(key) instead: ";
	auto &key = map.find(-5);
	if (key != map.end())
		cout << "\nFound " << key->first << ":" << key->second;
	else
		cout << "\nDid not find key=-5";
	cout << "\nUsed " << map.size() << " of " << map.bucket_count();

	cout << "\n\nNow, let's try to find map[-4] :";
	key = map.find(-4);
	if (key != map.end())
		cout << "\nFound " << key->first << ":" << key->second;
	else
		cout << "\nDid not find key=-5";
	cout << "\nUsed " << map.size() << " of " << map.bucket_count();


	cout << "\n\nWe can't achieve the same thing as map.erase(__) by just setting elements to NULL:";
	cout << "\nUsed " << map.size() << " of " << map.bucket_count();
	map[-4] = NULL;
	cout << "\nSetting map[-4] = NULL: ";
	if (map[-4] == NULL)
		cout << "It is NULL";
	cout << "\nUsed " << map.size() << " of " << map.bucket_count();

}

void un_map_test3() {//used to see the effect of table doubling (actually it becomes 8 times)
	std::unordered_map<int, int>map;
	char x;
	int i;
	long prev_bucket_count=1;
	for (i = 0; i <100000; i++) {
		map[i] = i;
		if (map.bucket_count() != prev_bucket_count) {
		cout << "\nUsed " << map.size() << " of " << map.bucket_count();
			prev_bucket_count = map.bucket_count();
		}
	}
	cout << "\n\n";
	cout << "\nUsed " << map.size() << " of " << map.bucket_count();
	cout << "\n\nDELETING:\n"; //to show that there is no halving
	prev_bucket_count = map.bucket_count();
	for (i = 0; i <100000; i++) {
		map.erase(i);
		if(i%500==0)
			cout << "\rUsed " << map.size() << " of " << map.bucket_count();
		if (map.bucket_count() != prev_bucket_count) {
			prev_bucket_count = map.bucket_count();
		}

	}

	cout << "\nThus, no table halving takes place.";
}

void un_map_test2() {
	char i;
	std::unordered_map<string, int> un_map;
	un_map["abc"] = 123;
	if (un_map["xyz"] == NULL)
		i = NULL;//something useless
	un_map["cde"] = 345;
	//std::unordered_map<string, int>::iterator iter;
	for (auto iter : un_map) { //only allowed in C++ 11 and above
							   //here, we acces only a copy of the data
		cout << iter.first << " :" << iter.second << endl;
	}
	for (auto &iter : un_map) { //"auto &iter" means we acces by reference, i.e. we change the actual data.
		if (iter.second != NULL)
			iter.second++;
	}
	cout << endl;
	for (auto iter : un_map) { //here, we acces only a copy of the data
		cout << iter.first << " :" << iter.second << endl;
	}

	cout << "\nUsed " << un_map.size() << " of " << un_map.max_size() << "\n\n\n";
}


void un_map_test4() {//testing map.bucket_size()
	std::unordered_map<int, int>map;
	long n = 30;
	long i;
	for (i = 0; i < n;i++) {
		map[i] = 100 * i;
	}
	cout << "\nUsed " << map.size() << " of " << map.bucket_count() << "\n";
	for (i = 0; i < map.bucket_count();i++) {
		cout << "\nBucket " << i << " Size: " << map.bucket_size(i);
	}

}

void un_map_test5() {//testing map.insert
	std::unordered_map<int, int>map;
	long i;
	cout << "\nInserting first element: map.insert({ 4,5 });";
	map.insert({ 4,5 });
	for (auto &iter : map)
		cout <<"\n"<< iter.first << ":" << iter.second;
	for (i = 0; i < map.bucket_count();i++) {
		cout << "\nBucket " << i << " Size: " << map.bucket_size(i);
	}

	cout << "\n\nInserting second element: map.insert({ 4,19 });";
	map.insert({ 4,19 });
	for (auto &iter : map)
		cout << "\n" << iter.first << ":" << iter.second;
	for (i = 0; i < map.bucket_count();i++) {
		cout << "\nBucket " << i << " Size: " << map.bucket_size(i);
	}
}
