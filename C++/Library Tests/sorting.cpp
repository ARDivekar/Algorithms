#include<algorithm>
#include<iostream>
#include<vector>

#include<time.h>
#include<stdio.h>

using namespace std;

vector<int>* generateRandomVector(int len, int rangeStart=0, int rangeEnd=0){
    if (rangeStart == 0 && rangeEnd == 0)
        rangeEnd = len;
    vector<int>* randomVec = new vector<int>();
    randomVec->reserve(len);
    srand(time(0));
    int i;
    for(i=0; i<len; i++)
        randomVec->push_back(rand()%(rangeEnd - rangeStart + 1) + rangeStart);
    return randomVec;
}

int main(){
    int i;
    const int n = 7;
    vector<int> a = *(generateRandomVector(50));

    cout<<"\nVector (size = "<<a.size()<<"):\n";
    for(i=0; i<a.size(); i++)
        cout<<a[i]<<"  ";
    cout<<endl;

    std::sort(a.begin(), a.end());

    cout<<"\nSorted Vector (size = "<<a.size()<<"):\n";
    for(i=0; i<a.size(); i++)
        cout<<a[i]<<"  ";
    cout<<endl;

    return 0;
}
