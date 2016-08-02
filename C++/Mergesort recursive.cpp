#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &a, vector<int> &c, int low, int high, int mid);
void mergesort(vector<int> &a, vector<int> &c, int low, int high){
    int mid;
    if (low < high){
        mid=(low+high)/2;
        mergesort(a, c, low, mid);
        mergesort(a, c, mid+1, high);
        merge(a, c, low, high, mid);
    }
    return;
}

void merge(vector<int> &a, vector<int> &c, int low, int high, int mid){
    int i, j, k;
    i = low;
    k = low;
    j = mid + 1;
    // standard merging from merge sort
    while (i <= mid && j <= high){
        if (a[i] < a[j]){
            c[k] = a[i];
            k++;
            i++;
        }
        else{
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid){
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high){
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
        a[i] = c[i];
}

void mergesort_driver(vector<int> &arr){
    int N = arr.size();
    vector<int> aux;
    aux.resize(N);
    mergesort(arr, aux, 0, N-1);
}

void printVec(const vector<int> &arr){
    cout<<endl;
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<"  ";
}

int main(){
    int N = 10;
    int* a =  new int[N]{6,8,3,9,0,4,5,1,2,7};
    vector<int> q (a, a+N);
    printVec(q);
    mergesort_driver(q);
    printVec(q);
    cout<<endl;
    return 0;
}
