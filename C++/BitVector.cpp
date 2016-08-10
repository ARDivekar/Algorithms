#include<iostream>
using namespace std;

// Source: http://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit-in-c-c
// And: http://stackoverflow.com/questions/2404439/how-do-i-bit-shift-a-long-by-more-than-32-bits

class BitVector{
    unsigned long long vec; // at max 64 bools.
public:
    BitVector(){
        vec = 0;
    }
    bool operator[](short i) const{
        return (vec >> i) & (unsigned long long)1;
    }
    void set(short i){
        vec |= ((unsigned long long)1 << i);  // (1<<i) = 2^i. e.g. (1<<2) = 4.
    }
    void clear(short i){
        vec &= ~((unsigned long long)1 << i); // ~ sign means flip all bits.
    }
    void toggle(short i){
        vec ^= ((unsigned long long)1 << i);
    }
    static short size(){
        return 64;
    }
};

int main(){
    BitVector b = *(new BitVector());
    b[0];
    int i;
    b.set(0);
    cout<<b[0]<<endl;
    b.clear(0);
    cout<<b[0]<<endl;
    b.toggle(0);
    cout<<b[0]<<endl;
    b.toggle(0);
    cout<<b[0]<<endl;
    //cout<<"\n\n\n"<<(1<<2);
    cout<<"\n\nPrint:";
    for(i=0; i<BitVector::size(); i++)
        cout<<"\n"<<b[i];

    for(i=0; i<BitVector::size(); i++){
        cout<<"\ni mod 7= "<<i<<" mod 7 = "<<(i%7);
        if(i%4==0){
            b.set(i);
        }
        cout<<"    "<<b[i];
    }

    cout<<"\n\nPrint:";
    for(i=0; i<BitVector::size(); i++)
        cout<<"\n"<<b[i];

    return 0;
}
