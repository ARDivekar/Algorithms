#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

void printArray(int* arr, int N){
    cout<<"  ";
    for(int i=0; i<N; i++)
        cout<<arr[i]<<"  ";
}

void integer_permutations(){
    // Gets all permutations of an array of integers
    const int N = 6;
    int* arr = new int[N]{1, 7, 3, 9, 2, 9}; // Repeeated numbers, thus we will only have 6!/2! = 720/2 = 360 permuations.
    cout<<"\nGetting all permutations of `"; printArray(arr, N); cout<<"`:\n";

    int i=1;
    sort(arr, arr+N); // sorts the string, passing the string by reference.
    cout<<(i++)<<" : "; printArray(arr, N); cout<<endl;    // Prints the first permutation, the sorted one.
    while(next_permutation(arr, arr+N)){ // You must pass the sorted string.
        cout<<(i++)<<" : "; printArray(arr, N); cout<<endl;
    }
}

void string_permutations(){
    // Gets all permutations of a string
    string str;
    str = "hello"; // repeated letters, will not give 5! outputs, it will give 5!/2! = 120/2 = 60 outputs.
    str = "a bee"; // Space is treated as a different alphabet.
    cout<<"\nGetting all permutations of `"<<str<<"`:\n";

    int i=1;
    sort(str.begin(), str.end()); // sorts the string, passing the string by reference.
    cout<<(i++)<<" : "<<str<<endl;    // Prints the first permutation, the sorted one.
    while(next_permutation(str.begin(), str.end())){ // You must pass the sorted string.
        cout<<(i++)<<" : "<<str<<endl;
    }
}

int main(){
    int i;
    // string_permutations();
    cout<<"\n\n\n";
    // integer_permutations();
    cout<<endl;
    return 0;
}
