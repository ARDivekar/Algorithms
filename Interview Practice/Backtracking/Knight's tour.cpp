/*
The knight is placed on the first block of an empty board and, moving according to the rules of chess, must visit each square exactly once.
*/
#include<iostream>
using namespace std;
class Point{
public:
    int i, j;
    Point(int i, int j)    {
        this->i = i;
        this->j = j;
    }
};

bool inBounds(int a, int b, int c){
    if(a<=b && b<=c)
        return true;
    return false;
}

Point getNextMove(int M, int N, Point current, int currentMoveNum){
    int x = current.i;
    int y = current.j;
    switch(currentMoveNum){
        case 1: x-=2; y+=1; break;  // Two up, one right
        case 2: x-=1; y+=2; break;  // One up, two right
        case 3: x+=1; y+=2; break;  // One down, two right
        case 4: x+=2; y+=1; break;  // Two down, one right
        case 5: x+=2; y-=1; break;  // Two down, one left
        case 6: x+=1; y-=2; break;  // One down, two left
        case 7: x-=1; y-=2; break;  // One up, two left
        case 8: x-=2; y-=1; break;  // Two up, one left
        default:
            return *(new Point(-1,-1));
    }
    if(inBounds(0,x,M-1) && inBounds(0,y,N-1))
        return *(new Point(x,y));
    return *(new Point(-1,-1));
}

bool allVisited(bool** visited, int M, int N){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j]==false)
                return false;
        }

    }
    return true;
}

void knightsTour_rec(bool** visited, int M, int N, Point current, bool &completedTour){
    visited[current.i][current.j] = true;
    //cout<<"\nVisited: "<<current.i<<", "<<current.j;
    int i;
    bool madeAMove = false;
    Point next(-1,-1);
    for(int i=1; i<=8; i++){
        next = getNextMove(M, N, current, i);
        if(next.i != -1 && next.j!=-1 && !visited[next.i][next.j]){
            madeAMove = true;
            knightsTour_rec(visited, M, N, next, completedTour);
        }
    }
    if(madeAMove == false){
        //cout<<"\nCould not go to any position from ("<<current.i<<", "<<current.j<<"), checking if done";
        if(allVisited(visited,M,N)){
            completedTour = true;
            //cout<<"\nTour is completed! Printing solution.\n";
        }
    }
    if(completedTour){
        cout<<"\n("<<current.i<<","<<current.j<<")";
        /*
            Alternatively, keep a matrix int pos[M][N], which stores the time when the index was found, and finally looks like this:
                 0  59  38  33  30  17   8  63
                37  34  31  60   9  62  29  16
                58   1  36  39  32  27  18   7
                35  48  41  26  61  10  15  28
                42  57   2  49  40  23   6  19
                47  50  45  54  25  20  11  14
                56  43  52   3  22  13  24   5
                51  46  55  44  53   4  21  12
        */
    }
    else{
        visited[current.i][current.j] = false;
    }
}


bool knightsTour(int M, int N, Point start){
    int i,j;
    bool** visited = new bool*[M];
    for(i=0; i<M; i++)
        visited[i] = new bool[N]{0};
    bool completedTour = false;
    knightsTour_rec(visited, M, N, start, completedTour);
    return completedTour;
}


int main(){
    for(int i=1; i<=10; i++){
        cout<<"\n\n\n\nCan complete tour with matrix of size "<<i<<"x"<<i<<": ";
        cout<<"\nConclusion: "<<knightsTour(i,i,*(new Point(0,0)));
    }
    cout<<endl;
    return 0;
}
