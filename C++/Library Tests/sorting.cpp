#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
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


    // Sorting a vector of integers:
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

    cout<<"\n\n\n";


    // Sorting a vector of strings: just use sort() like normal.
    vector<string> strs;
    strs.push_back("javascript");
    strs.push_back("dastardly");
    strs.push_back("abacus");
    strs.push_back("aberration");
    strs.push_back("xylophone");
    strs.push_back("linguini");

    cout<<"\nVector (size = "<<strs.size()<<"):\n";
    for(i=0; i<strs.size(); i++)
        cout<<strs[i]<<"  ";
    cout<<endl;

    std::sort(strs.begin(), strs.end());

    cout<<"\nSorted Vector (size = "<<strs.size()<<"):\n";
    for(i=0; i<strs.size(); i++)
        cout<<strs[i]<<"  ";
    cout<<endl;



    cout<<"\n\n\n";
    return 0;
}
