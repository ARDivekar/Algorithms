#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

// Source: http://stackoverflow.com/a/2710716/4900327


int permutations(int currentSize, vector<int> &a, int &num_permutations) {
    // only works if all elements are distinct.
    int i;
    if (a.size()-1 == currentSize) {
        num_permutations++;
        cout<<"\n"<<num_permutations<<" : \t";
        for(i=0; i<a.size(); i++)
            cout<<a[i]<<" ";
    }
    else {
        for (i=currentSize+1; i<=a.size(); i++) {
            permutations(currentSize+1, a, num_permutations);
            if (i<a.size()){
                // Swap the elements:
                int temp=a[currentSize];
                a[currentSize]=a[i];
                a[i]=temp;
            }
        }
    }
    return num_permutations;
}


int main(){
    vector<int> seq;
    seq.push_back(1);
    seq.push_back(5);
    seq.push_back(2);
    seq.push_back(4);
    seq.push_back(3);
    int num_permutations = 0;
    cout<<"\n"<<permutations(0, seq, num_permutations); // only works if all elements are distinct.
    cout<<endl;
    return 0;
}
