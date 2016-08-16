// This file shows the features of the <list>
// Great reference link: http://www.cs.northwestern.edu/~riesbeck/programming/c++/stl-summary.html
// And: http://stackoverflow.com/questions/181693/what-are-the-complexity-guarantees-of-the-standard-containers
#include<iostream>
#include<list>
using namespace std;


void printList(list<int> L){
    list<int>::iterator iter;
    cout<<endl;
    for(iter=L.begin(); iter!=L.end(); iter++)
        cout<<(*iter)<<"  ";
    cout<<endl;
}



void listTest(){
    /*
    <list> is implemented as a DOUBLY LINKED LIST (http://stackoverflow.com/a/5022084/4900327)

    <list> functions:
        Constructors & initializaers:
            list<T> L;    Make an empty list; O(1)
            list<T> L(L2.begin(), L2.end());    Make a list and copy the values from begin to end; O(n)
            L.assign(begin, end);   Clear the container and copy in the elements from begin to end; O(n)

        Front & back accessors (does not remove):
            L.front()   Return the first element; O(1)
            L.back()    Return the last element; O(1)

        Random element accessors:
            Not possible. Only iterators L.begin() and L.end().

        Insertion:
            L.push_front(value)     Add value to front; O(1)
            L.push_back(value)	    Add value to end; O(1)
            L.insert(iter, value)	Insert value after position indexed by list<T>::iterator iter; O(1)

        Deletion:
            L.pop_front()           Remove value from front; O(1)
            L.pop_back()            Remove value from end; O(1)
            L.erase(iter)           Erase value indexed by list<T>::iterator iter; O(1)
            L.erase(pos1, pos2)	    Erase the elements from list<T>::iterator pos1 upto (but not including) list<T>::iterator pos2; NOTE: pos2 is not erased. O(1)
            L.remove(value)	        Remove all occurrences of value; O(n)


        Reordering:
            L.reverse()             Reverse the list; O(n)
            L.sort()                Sort the list; O(n log n)
            L.sort(comparison)      Sort with comparison function; O(n logn)

        Concatenation:
            L.merge(L2)	            Attempt SORTED MERGE (like in mergesort), save in L; O(n)
    */

    list<int> L;
    L.push_back(1);
    L.push_back(3);
    L.push_back(5);
    L.push_back(7);
    L.push_back(9);
    L.push_back(11);
    cout<<"\n<list> L: ";
    printList(L);

    cout<<"\n\nReversing list with `L.reverse()` :";
    L.reverse();
    cout<<"\n<list> L: ";
    printList(L);

    cout<<"\n\nSorting with `L.sort()` :";
    L.sort();
    cout<<"\n<list> L: ";
    printList(L);



    cout<<"\n\nReversing and sorting with `L.sort(cmp)` :";
    L.reverse();

    // Source: http://fusharblog.com/3-ways-to-define-comparison-functions-in-cpp/ and http://stackoverflow.com/a/4324780/4900327
    struct tempCmp{
        static bool lessThanCmp(int &a, int &b){
            return a<b;
        }
    };
    L.sort(tempCmp::lessThanCmp);
    cout<<"\n<list> L: ";
    printList(L);



    list<int> L2;
    L2.push_back(2);
    L2.push_back(4);
    L2.push_back(6);
    L2.push_back(8);
    L2.push_back(10);
    L2.push_back(12);
    cout<<"\n\n\n\n<list> L2: ";
    printList(L2);

    L.merge(L2);
    cout<<"\nCompleted sorted mergesort-merge via `L.merge(L2)` :";
    cout<<"\n<list> L: ";
    printList(L);
    cout<<"\n<list> L2: (is empty after L.merge(__))";
    printList(L2);

    cout<<"\n\n\n\nDeleting elements 3, 4, 8, 6 from L via `L.remove(__)`";
    L.remove(3);
    L.remove(4);
    L.remove(6);
    L.remove(8);
    cout<<"\n<list> L: ";
    printList(L);

    L2.push_back(2);
    L2.push_back(4);
    L2.push_back(6);
    L2.push_back(8);
    L2.push_back(10);
    L2.push_back(12);
    cout<<"\n\nReset L2: ";
    cout<<"\n<list> L2: ";
    printList(L2);

    list<int>::iterator pos1 = L2.begin();
    list<int>::iterator pos2 = L2.end();
    pos1++;
    pos2--;
    cout<<"\n\n\n\nAccessing some list elements via iterators:";
    cout<<"\n`list<int>::iterator pos1 = L2.begin();    pos1++; `";
    cout<<"\n`list<int>::iterator pos2 = L2.end();    pos2--; `";
    cout<<"\n(*pos1) = "<<(*pos1);
    cout<<"\n(*pos2) = "<<(*pos2);

    cout<<"\n\n\nDeleting some more elements via `L.erase(pos1, pos2)`";
    L2.erase(pos1, pos2);
    cout<<"\n<list> L2: ";
    printList(L2);



    list<int> L3;
    L3.push_back(4);
    L3.push_back(3);
    L3.push_back(8);
    L3.push_back(6);
    cout<<"\n<list> L3: ";
    printList(L3);

    L.merge(L3);
    cout<<"\nAttempted sorted mergesort-merge via `L.merge(L3)` (won't work unless both lists are sorted):";
    cout<<"\n<list> L: ";
    printList(L);
}



int main(){

    listTest();
    cout<<endl;
    return 0;
}
