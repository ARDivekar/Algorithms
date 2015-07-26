#include<iostream>
using namespace std;

int nonRepeatingElement(int* a, int len) {
	int element = 0;
 	for (int i = 0; i < len; i++) {	   
		element = element^a[i];
    }
 
    return element;
}


int main(){
	int a[] = { 3, 4, 1, 3, 1, 7, 2,2, 2, 4 };
	cout<<nonRepeatingElement(a,10);
}
 



