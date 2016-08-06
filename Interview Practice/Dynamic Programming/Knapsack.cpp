#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int max(int a, int b){
    return a > b? a : b;
}

int knapsack(map<string, int*> &items, int C, bool printing=true){ // C = capacity of knapsack
    int* opt = new int[C+1];
    opt[0] = 0;
    int i,j;
    string* whichItem = new string[C+1];
    whichItem[0] = "";

    map<string, int*>::iterator iter;
    for(i=1; i<=C; i++){
        opt[i] = opt[i-1];
        whichItem[i] = "";
        for(iter=items.begin(); iter!=items.end(); iter++){
            if(i-iter->second[0] >= 0 ){ // make sure you don't go below weight of 0.
                if(opt[i - iter->second[0]]+iter->second[1] > opt[i]){
                    opt[i] = opt[i - iter->second[0]]+iter->second[1]; // Max of the previous max, and the value of the item.
                    whichItem[i] = iter->first;
                }

            }
        }
    }

    // print the solution.
    if(printing){
        map<string, int> itemCounts;
        for(iter=items.begin(); iter!=items.end(); iter++){
            itemCounts[iter->first] = 0;
        }

        string item = whichItem[C];
        i = C;
        while(i>0){
            if(item!=""){
                //cout<<item<<"("<<items[item][1]<<")  ";
                itemCounts[item]++;
                i = i - items[item][0];
            }
            else {
                i--;
            }
            item = whichItem[i];

        }
        // print all counts;
        map<string, int>::iterator itemCountsIter;
        for(itemCountsIter=itemCounts.begin(); itemCountsIter!=itemCounts.end(); itemCountsIter++){
            if(itemCountsIter->second>0)
            cout<<"\n    "<<itemCountsIter->first<<" (weight = "<<items[itemCountsIter->first][0]<<",   value = "<<items[itemCountsIter->first][1]<<") : "<<itemCountsIter->second;
        }

        cout<<endl;
    }
    return opt[C];
}

int knapsack_01(map<string, int*> &items, int C){
    int N = items.size();
    int **opt = new int*[N+1];
    int i,j;
    for(i=0; i<=N; i++){
        opt[i] = new int[C+1]{0}; // Initialization: first row and first column zeroed out.
    }
    // opt is now a (N+1)x(C+1) array

    map<string, int*>::iterator iter;
    i = 1;
    int itemWeight, itemVal;
    for(iter=items.begin(); iter!=items.end() && i<=N; iter++, i++){
        itemWeight = iter->second[0];
        itemVal = iter->second[1];
        for(j=1; j<=C; j++){
            opt[i][j] = opt[i-1][j];
            if(j-itemWeight >= 0){
                opt[i][j] = max(opt[i][j], opt[i-1][j-itemWeight]+itemVal);
            }
        }
    }

    int maxVal = -1;
    for(j=0; j<=C; j++){
        maxVal = max(maxVal, opt[N][j]);
    }
    return maxVal;
}

/*
// Versions without <map>
int knapsack_01(int C, int weights[], int vals[], int N){
    int i,j;
    int** opt = new int*[N+1];
    for(i=0; i<=N; i++)
        opt[i] = new int[C+1];

    for(i=0; i<=N; i++){
        for(j=0; j<=C; j++){
            if(i==0 || j==0)
                opt[i][j] = 0;
            else{
                opt[i][j] = opt[i-1][j];
                if(j-weights[i] >= 0){ // it still fits in the knapsack.
                    opt[i][j] = max(opt[i][j], opt[i-1][j-weights[i]] + val[i-1]);
                }
            }
        }
    }

    int maxVal = -1;
    for(j=0; j<=C; j++){
        maxVal = max(maxVal, opt[N][j]);
    }
    return maxVal;
}

*/



int main(){
    map<string, int*> items; // Weight,  Value
    items["gold"]     = new int[2]{ 10,   40 };
    items["silver"]   = new int[2]{  7,   25 };
    items["bronze"]   = new int[2]{  5,   10 };
    items["artifact"] = new int[2]{ 11,   43 };
    items["skull"]    = new int[2]{  3,    8 };
    const int C_start=0;
    int iterCount, C, val;

    for(C=C_start, iterCount=50; iterCount>0; C+=int(1), iterCount--){
        cout<<"Knapsack with capacity = "<<C<<" : ";
        val = knapsack(items, C);
        cout<<"Max value = "<<val;
        cout<<"\n\n\n\n";
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    for(C=C_start, iterCount=50; iterCount>0; C+=int(1), iterCount--){
        cout<<"Knapsack_0/1 with capacity = "<<C<<" : ";
        val = knapsack_01(items, C);
        cout<<"Max value = "<<val;
        cout<<"\n\n";
    }
    cout<<endl;
    return 0;
}
