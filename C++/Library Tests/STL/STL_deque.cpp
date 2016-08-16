// This file shows the features of the <vector>
// Great reference link: http://www.cs.northwestern.edu/~riesbeck/programming/c++/stl-summary.html
// And: http://stackoverflow.com/questions/181693/what-are-the-complexity-guarantees-of-the-standard-containers


#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

void printDeque(deque<int> a){
    cout<<endl;
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}

void testDeque(){
    /*
    <deque> stands for double-ended queue (meaning you can insert and remove from both ends in O(1) time), and is an interesting data structure, basically a vector of fixed-sized arrays. See http://stackoverflow.com/a/6292437/4900327 for more info.
    [Legend:  *** = be careful]

    <deque> functions:
        Constructors & initializaers {Same as <vector>}:
            deque<T> D;                Make an empty deque; O(1)
            deque<T> D(n);	           Make a deque with N elements; O(n)
            deque<T> D(n, value);      Make a deque with N elements, initialized to value; O(n)
            deque<T> D(begin, end);    Make a deque and copy the elements from begin to end; O(n)
            D.assign(begin, end);      Clear the container and copy in the elements from begin to end; O(n)

        Size & resizing:
            D.size()                Returns the number of elements in the vector.
                                    NOTE: <deque> does not have D.capacity()
            D.resize(newSize)       Change the size and initializes the memory (might have zeros appearing at the end).
                                    NOTE: <deque> does not have D.reserve(__)


        Front & back accessors (does not remove):
            D.front()   Return the first element; O(1)
            D.back()    Return the last element; O(1)

        Random element accessors {Same as <vector>}:
            D[i]        Return the i'th element; O(1)
            Iterators:  D.begin() and D.end()

        Insertion:
            D.push_front(value)     Add value to front; O(1) AMORTIZED
            D.push_back(value)	    Add value to end; O(1) AMORTIZED
            D.insert(iter, value)	***Insert at position indexed by deque<T>::iterator iter; O(n)

        Deletion:
            D.pop_front()           Remove value from front; O(1)
            D.pop_back()            Remove value from end; O(1)
            D.erase(iter)           ***Erase value indexed by deque<T>::iterator iter; O(n)
            D.erase(pos1, pos2)	    ***Erase the elements from deque<T>::iterator pos1 upto (but not including) deque<T>::iterator pos2; NOTE: pos2 is not erased. O(n)
            D.clear()               Remove all elements.

        Reordering {Same as <vector>}:
            reverse(A.begin(), A.end());     (from <algorithm>) Reverse the vector; O(n)
            sort(A.begin(), A.end());        (from <algorithm>) Sort the vector; O(n log n)
            sort(A.rbegin(), A.rend());      (from <algorithm>) Reverse-Sort the vector; O(n log n)
            sort(A.begin(), A.end(), cmp);   (from <algorithm>) Sort the vector with explicit comparison function; O(n logn)

        Concatenation & Swap {Same as <vector>}:
            A.swap(B);      Swap the elements of both vectors. e.g. A={1,2,3} becomes B={7,8} and vice verca.
            A.insert(A.end(), B.begin(), B.end());      Concatenate A with B.
    */

    deque<int> D;
    D.push_back(4);
    D.push_back(2);
    D.push_back(1);
    D.push_back(3);
    printDeque(D);
    reverse(D.begin(), D.end());
    printDeque(D);
    sort(D.begin(), D.end());
    printDeque(D);
    sort(D.rbegin(), D.rend());
    printDeque(D);
}


int main(){

    testDeque();
    cout<<endl;
    return 0;
}
