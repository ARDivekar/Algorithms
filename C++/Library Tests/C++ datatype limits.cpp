#include<iostream>
#include<limits.h>
#include<math.h>

using namespace std;

void testUnsignedLongLong(){
    unsigned long long data;
    data = ULLONG_MAX;
    cout<<"\n\nunsigned long long:";
    cout<<"\n\tMaximum value (from ULLONG_MAX):  "<<data;
    data += 1;
    cout<<"\n\tWraparound value: \t\t  "<<data;
    data += 1;
    cout<<"\n\t(Wraparound value + 1): \t  "<<data;
    data += 1;
    cout<<"\n\t(Wraparound value + 2): \t  "<<data;

    cout<<"\n\tWe can generate ULLONG_MAX by : ` ( ((unsigned long long)1<<64) -1) ` : ";
    cout<<( ((unsigned long long)1<<64) -1);
    cout<<endl;
}

void testLongLong(){
    long long data;
    data = LLONG_MAX;
    cout<<"\n\nlong long:";
    cout<<"\n\tMaximum value (from LLONG_MAX):  "<<data;
    data += 1;
    cout<<"\n\tWraparound value: \t\t"<<data;
    data += 1;
    cout<<"\n\t(Wraparound value + 1): \t"<<data;
    data += 1;
    cout<<"\n\t(Wraparound value + 2): \t"<<data;
    cout<<endl;
}



int main(){
    testUnsignedLongLong();
    testLongLong();
    cout<<endl;
    return 0;
}
