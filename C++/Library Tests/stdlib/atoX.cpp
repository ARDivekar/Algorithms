#include<iostream>
#include<stdlib.h>
using namespace std;

void atoiTest(){
    cout << "\natoi() Test:\n";
    char a[] = "00999";
    cout<<"\tString: >"<<a<<"<";
    cout <<"\n\tLength: " << sizeof(a)/sizeof(char);
    int val = (atoi(a)+1000);
    cout<<"\n\tInteger val +1000: ";
    cout<< val <<"\n\n";
}

void atolTest(){
    cout << "\natol() Test:\n";
    char a[] = "  00999  ";
    cout<<"\tString: >"<<a<<"<";
    cout <<"\n\tLength: " << sizeof(a)/sizeof(char);
    long val = (atol(a)+1000);
    cout<<"\n\tLong val +1000: ";
    cout<< val <<"\n\n";
}


void atofTest(){
    cout << "\natof() Test:\n";
    char a[] = "  0300999.18";
    cout<<"\tString: >"<<a<<"<";
    cout <<"\n\tLength: " << sizeof(a)/sizeof(char);
    double val = double(atof(a))+0.72;
    cout<<"\n\tDouble val +0.72: ";
    cout<< val;
    cout<<"\n\n";
}


int main(){

    atoiTest();
    atolTest();
    atofTest();
    cout<<endl;
    return 0;
}
