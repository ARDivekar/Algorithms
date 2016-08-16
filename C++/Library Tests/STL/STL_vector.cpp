// This file shows the features of the <vector>
// Great reference link: http://www.cs.northwestern.edu/~riesbeck/programming/c++/stl-summary.html
// And: http://stackoverflow.com/questions/181693/what-are-the-complexity-guarantees-of-the-standard-containers
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVec(vector<int> a){
    cout<<endl;
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}

void testVec(){
    /*
    <vector> is implemented with a normal dynamically-allocated array, that is reallocated when its capacity is exhausted (usually doubling its size or something like that).
    [Legend:  *** = be careful]

    <vector> functions:
        Constructors & initializaers:
            vector<T> A;                Make an empty vector; O(1)
            vector<T> A(n);	            Make a vector with N elements; O(n)
            vector<T> A(n, value);      Make a vector with N elements, initialized to value; O(n)
            vector<T> A(begin, end);    Make a vector and copy the elements from begin to end; O(n)
            A.assign(begin, end);       Clear the container and copy in the elements from begin to end; O(n)

        Size & resizing:
            A.size()                Returns the number of elements in the vector.
            A.capacity()            Returns the size allocated to the vector.
            A.resize(newSize)       Change the size and initializes the memory (might have zeros appearing at the end).
            A.reserve(newCapacity)  Allocates memory, increasing capacity() but not size(). Memory is not accessible unless we use push_back etc.

        Front & back accessors (does not remove):
            A.front()   Return the first element; O(1)
            A.back()    Return the last element; O(1)

        Random element accessors:
            A[i]        Return the i'th element; O(1)
            Iterators:  A.begin() and A.end()

        Insertion:
            A.push_back(value)	    Add value to end; O(1) AMORTIZED
                                    NOTE: A.push_front(value) does not exist as it would be O(n)
            A.insert(iter, value)	***Insert at position indexed by vector<T>::iterator iter; O(n)

        Deletion:
            A.pop_back()            Remove value from end; O(1)
                                    NOTE: A.pop_front() does not exist as it would be O(n)
            A.erase(iter)           ***Erase value indexed by vector<T>::iterator iter; O(n)
            A.erase(pos1, pos2)	    ***Erase the elements from vector<T>::iterator pos1 upto (but not including) vector<T>::iterator pos2; NOTE: pos2 is not erased. O(n)
            A.clear()               Remove all elements.

        Reordering:
            reverse(A.begin(), A.end());     (from <algorithm>) Reverse the vector; O(n)
            sort(A.begin(), A.end());        (from <algorithm>) Sort the vector; O(n log n)
            sort(A.rbegin(), A.rend());      (from <algorithm>) Reverse-Sort the vector; O(n log n)
            sort(A.begin(), A.end(), cmp);   (from <algorithm>) Sort the vector with explicit comparison function; O(n logn)

        Concatenation & Swap:
            A.swap(B);      Swap the elements of both vectors. e.g. A={1,2,3} becomes B={7,8} and vice verca.
            A.insert(A.end(), B.begin(), B.end());      Concatenate A with B.
    */

    vector<int> a(3);
    a[0]=1;
    a[1]=2;
    a[2]=3;
    printVec(a);
    reverse(a.begin(), a.end());
    printVec(a);

    vector<int> b(2);
    b[0]=7;
    b[1]=8;

    a.swap(b);
    printVec(a);
    printVec(b);
}


int main(){
    testVec();
    cout<<endl;
    return 0;
}
