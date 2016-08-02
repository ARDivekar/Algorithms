#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &a, vector<int> &c, int low, int high, int mid, long long &count);
void mergesort(vector<int> &a, vector<int> &c, int low, int high, long long &count){
    int mid;
    if (low < high){
        mid=(low+high)/2;
        mergesort(a, c, low, mid, count);
        mergesort(a, c, mid+1, high, count);
        merge(a, c, low, high, mid, count);
    }
    return;
}

void merge(vector<int> &a, vector<int> &c, int low, int high, int mid, long long &count){  //to store the inversion count
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

            count += (long long)mid - (long long) i + 1L; // This is where the trick occurs, if X > Y,
            //eg. in [3, 4, 5] and [1,2]
            //if(3>1) then 4,5 is obviously greater then 1, thus making count as mid - i+1
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
    for (i = low; i < k; i++){
        a[i] = c[i];
    }
}

long long numInversions(vector<int> arr){
    long long count=0;
    int N = arr.size();
    vector<int> aux;
    aux.resize(N);
    mergesort(arr, aux, 0, N-1, count);
    return count;
}


void printVec(const vector<int> &arr){
    cout<<endl;
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<"  ";
}


int main(){
    vector<int> q;
    q.push_back(2);
    q.push_back(1);
    q.push_back(5);
    q.push_back(3);
    q.push_back(4);
    printVec(q);
    cout<<"\nNum inversions:"<<numInversions(q);
    printVec(q);
    cout<<endl;
    return 0;
}
