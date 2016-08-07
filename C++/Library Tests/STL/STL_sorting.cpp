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

void sortVectorOfIntegers(){
    int i;
    // Sorting a vector of integers:
    vector<int> a = *(generateRandomVector(50));

    cout<<"\nVector of integers (size = "<<a.size()<<"):\n";
    for(i=0; i<a.size(); i++)
        cout<<a[i]<<"  ";
    cout<<endl;

    std::sort(a.begin(), a.end());

    cout<<"\nSorted Vector of integers (size = "<<a.size()<<"):\n";
    for(i=0; i<a.size(); i++)
        cout<<a[i]<<"  ";
    cout<<endl;

}

void sortString(){
    string str = "hulabaloo";
    cout<<"\nString before sorting: "<<str<<"\n";
    std::sort(str.begin(), str.end());
    cout<<"\nString after sorting: "<<str<<"\n";
}

void sortVectorOfStrings(){
    // Sorting a vector of strings: just use sort() like normal.
    int i;
    vector<string> strs;
    strs.push_back("javascript");
    strs.push_back("dastardly");
    strs.push_back("abacus");
    strs.push_back("aberration");
    strs.push_back("xylophone");
    strs.push_back("linguini");

    cout<<"\nVector of string (size = "<<strs.size()<<"):\n";
    for(i=0; i<strs.size(); i++)
        cout<<strs[i]<<"  ";
    cout<<endl;

    std::sort(strs.begin(), strs.end());

    cout<<"\nSorted Vector of string (size = "<<strs.size()<<"):\n";
    for(i=0; i<strs.size(); i++)
        cout<<strs[i]<<"  ";
    cout<<endl;
}






class Node{
public:
    int data;
    Node(int data=0){
        this->data = data;
    }

    friend ostream& operator<<(ostream& os, const Node &node){
        os << node.data;
        return os;
    }

    bool operator<(const Node &A)    // checks if (this < A)
    const{
        if(this->data < A.data)
            return true;
        return false;
    }

    bool operator>(const Node &A)    // checks if (this > A)
    const{
        if(this->data > A.data)
            return true;
        return false;
    }
};


void sortVectorOfNodes(){
    int i;
    vector<Node> nodes;
    nodes.push_back(*(new Node(5)));
    nodes.push_back(*(new Node(3)));
    nodes.push_back(*(new Node(7)));
    nodes.push_back(*(new Node(1)));
    nodes.push_back(*(new Node(2)));

    cout<<"\nVector of Nodes (size = "<<nodes.size()<<"):\n";
    for(i=0; i<nodes.size(); i++)
        cout<<nodes[i]<<"  ";
    cout<<endl;

    std::sort(nodes.begin(), nodes.end());

    cout<<"\nSorted Vector of Nodes (size = "<<nodes.size()<<"):\n";
    for(i=0; i<nodes.size(); i++)
        cout<<nodes[i]<<"  ";
    cout<<endl;
}

class Box{
public:
    int length;
    int breadth;
    int height;

    Box(int length, int breadth, int height){
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    int volume() const{
        return this->length*this->breadth*this->height;
    }

    friend ostream& operator<<(ostream& os, const Box &box){
        os << box.volume();
        return os;
    }


    bool operator<(const Box &A) // checks if (this < A)
    const{
        if(this->volume() < A.volume())
            return true;
        return false;
    }

    bool operator>(const Box &A) // checks if (this > A)
    const{
        if(this->volume() > A.volume())
            return true;
        return false;
    }
};



void sortVectorOfBoxes(){
    int i;
    vector<Box> boxes;
    boxes.push_back(*(new Box(5, 7, 9)));
    boxes.push_back(*(new Box(3, 2, 1)));
    boxes.push_back(*(new Box(7, 3, 3)));
    boxes.push_back(*(new Box(1, 4, 5)));
    boxes.push_back(*(new Box(2, 2, 2)));

    cout<<"\nVector of Boxes (size = "<<boxes.size()<<"):\n";
    for(i=0; i<boxes.size(); i++)
        cout<<boxes[i]<<"  ";
    cout<<endl;

    std::sort(boxes.begin(), boxes.end());  // not working

    cout<<"\nSorted Vector of Boxes (size = "<<boxes.size()<<"):\n";
    for(i=0; i<boxes.size(); i++)
        cout<<boxes[i]<<"  ";
    cout<<endl;
}


int main(){
    sortVectorOfIntegers();
    cout<<"\n\n\n";
    sortString();
    cout<<"\n\n\n";
    sortVectorOfStrings();
    cout<<"\n\n\n";
    sortVectorOfNodes();
    cout<<"\n\n\n";
    sortVectorOfBoxes();
    cout<<"\n\n\n";
    return 0;
}
