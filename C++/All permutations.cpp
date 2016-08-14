#include<iostream>
#include<vector>
using namespace std;

void printVec(vector<int> &a, int count){
    cout<<"\n"<<count<<" :\t";
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
}

// Source: https://www.wikiwand.com/en/Heap's_algorithm
void generatePermsRecursive(int n, vector<int> &a, int &count){
    if (n == 1){
        count++;
        printVec(a, count);
    }
    else{
        int i;
        for(i = 0; i < n-1; i++){
            generatePermsRecursive(n-1, a, count);
            if(i%2==0){
                int temp = a[i];
                a[i] = a[n-1];
                a[n-1] = temp;
            }
            else{
                int temp = a[0];
                a[0] = a[n-1];
                a[n-1] = temp;
            }
        }
        generatePermsRecursive(n-1, a, count);
    }
}


// Source: https://www.wikiwand.com/en/Heap's_algorithm
void generatePermsIterative(vector<int> &a){
    int n = a.size();
    vector<int> c(n);
    int i;
    for(i=0; i<n; i++)
        c[i] = 0;

    i=0;
    int count=1;
    printVec(a, count);
    while(i<n){
        if(c[i] < i){
            if(i%2==0){
                int temp = a[0];
                a[0] = a[i];
                a[i] = temp;
            }
            else{
                int temp = a[c[i]];
                a[c[i]] = a[i];
                a[i] = temp;
            }
            count+=1;
            printVec(a, count);
            c[i]+=1;
            i = 0;
        }
        else{
            c[i] = 0;
            i += 1;
        }
    }
}


// Source: https://see.stanford.edu/materials/icspacs106b/H19-RecBacktrackExamples.pdf
void RecPermuteStrings(string soFar, string rest, int &count){
    if (rest.empty()) {
        count+=1;
        cout << count << " : " << soFar << endl;
    }
    else {
        for (int i = 0; i < rest.length(); i++) {
            string remaining = rest.substr(0, i) + rest.substr(i+1); // missing out the i'th element
            RecPermuteStrings(soFar + rest[i], remaining, count);
        }
    }
}


void RecPermuteVectors(vector<int> soFar, vector<int> rest, int &count){
    if(rest.size()==0){
        count+=1;
        printVec(soFar, count);
    }
    else{
        for (int i = 0; i < rest.size(); i++) {
            vector<int> remaining;
            vector<int> newSoFar;
            newSoFar.insert(newSoFar.end(), soFar.begin(), soFar.end());
            newSoFar.insert(newSoFar.end(), rest.begin()+i, rest.begin()+i+1);
            remaining.insert(remaining.end(), rest.begin(), rest.begin() + i);
            remaining.insert(remaining.end(), rest.begin()+ i+1, rest.end()); // Miss i'th element.

            // cout<<"\n\n\n";
            // cout<<"\nrest: ";
            // printVec(rest, 0);
            // cout<<"\nSo far: ";
            // printVec(newSoFar, 0);
            // cout<<"\nremaining: ";
            // printVec(remaining, 0);

            RecPermuteVectors(newSoFar, remaining, count);
        }
    }

}



int main(){
    int count = 0;
    vector<int> a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    generatePermsIterative(a);

    cout<<"\n\n\n";
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    generatePermsRecursive(a.size(), a, count);

    cout<<"\n\n\n";
    count = 0;
    RecPermuteStrings("", "abcde", count);

    cout<<"\n\n\n";
    count = 0;
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    RecPermuteVectors(*(new vector<int>()), a, count);
    cout<<endl;
    return 0;
}
