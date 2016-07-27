#include<vector>
#include<iostream>
#include<time.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


vector<int>* generateRandomVector(int len, int rangeStart=0, int rangeEnd=0){
    if (rangeStart == 0 && rangeEnd == 0)
        rangeEnd = len;
    vector<int>* randomVec = new vector<int>();
    randomVec->reserve(len);
    srand(time(NULL));
    int i;
    for(i=0; i<len; i++)
        randomVec->push_back(rand()%(rangeEnd - rangeStart + 1) + rangeStart);
    return randomVec;
}


int* generateRandomArray(int len, int rangeStart=0, int rangeEnd=0){
    if (rangeStart == 0 && rangeEnd == 0)
        rangeEnd = len;
    int* randomArr = new int[len];
    srand(time(NULL));

    for(int i=0; i<rand()%(len*len); i++); // This resets rand() to some random value, useful when generateRandomArray() and generateRandomVector() are called in succession.

    int i;
    for(i=0; i<len; i++)
        randomArr[i]=(rand()%(rangeEnd - rangeStart + 1) + rangeStart);
    return randomArr;
}

void printArray(int* arr, int len){
    for(int i=0; i<len; i++){
        cout<<arr[i]<<"  ";
    }
}

void printVector(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<"  ";
    }
}


int main(){
    const int n = 10;
    const int rangeStart = 1;  // inclusive
    const int rangeEnd = 1000;  // inclusive

    int* a = generateRandomArray(n, rangeStart, rangeEnd);
    cout<<"\nRandom Array (size = "<<n<<"):\n"; printArray(a,n); cout<<"\n";

    vector<int> vec = *(generateRandomVector(n, rangeStart, rangeEnd));
    cout<<"\nRandom Vector (size = "<<n<<"):\n"; printVector(vec); cout<<"\n";

    cout<<endl;
    return 0;
}
