#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

class Seq{
public:
    int start;
    int end;
    Seq(){
        start = -1; end = -1;
    }
    Seq(int start, int end){
        this->start = start;
        this->end = end;
    }

    bool operator<(const Seq &A){
        return (this->start < A.start);
    }
};

int max(int a, int b){
    return a>b? a:b;
}

int min(int a, int b){
    return a<b? a:b;
}

void printList(list<Seq> &a){
    cout<<endl;
    list<Seq>::iterator iter = a.begin();
    for(; iter!=a.end(); iter++)
        cout<<"\n("<<iter->start<<", "<<iter->end<<")";
    cout<<endl;
}

list<Seq> mergeSeqs(list<Seq> seqs){
    if(seqs.size()==1)
        return seqs;

    seqs.sort();
    cout<<"\nBefore merging: ";
    printList(seqs);

    list<Seq>::iterator prev = seqs.begin();
    list<Seq>::iterator iter = seqs.begin(); iter++;
    while(iter!=seqs.end()){
        if(prev->start < iter->start && iter->start <= prev->end){
            iter->start = min(iter->start,prev->start);
            iter->end = max(iter->end, prev->end);
            seqs.erase(prev);
        }
        // else the two intervals are non-overlapping.
        prev = iter;
        iter++;
    }

    cout<<"\nAfter merging: ";
    printList(seqs);
    return seqs;
}



int main(){
    list<Seq> seqs;
    seqs.push_back(*(new Seq(12,20)));
    seqs.push_back(*(new Seq(2,5)));
    seqs.push_back(*(new Seq(10,14)));
    seqs.push_back(*(new Seq(1,4)));
    seqs.push_back(*(new Seq(7,15)));
    mergeSeqs(seqs);
    // printList(seqs);
    cout<<endl;
    return 0;
}
