#include<iostream>

using namespace std;

int main(){
    // C++11 syntax:
	int i,j;

    int* arrInitToZero = new int[256]{0}; // Only works for zero.

    int* arr1d = new int[5]{2,7,1,9,3};
    // Print 1D array:
    cout<<"\n\n1D array:";
    cout<<"\n\t";
    for(i=0; i<5; i++)
        cout<<arr1d[i]<<"  ";
    cout<<endl;



    int** arr2d = new int*[4]{
		new int[2]{1,2},
		new int[2]{3,8},
		new int[2]{2,5},
		new int[2]{7,3}
	};
    // Print 2D array:
    cout<<"\n\n2D array:";
    for(i=0; i<4; i++){
        cout<<"\n\t";
        for(j=0; j<2; j++)
            cout<<arr2d[i][j]<<"  ";
    }
    cout<<endl;

    cout<<endl;
    return 0;
}
