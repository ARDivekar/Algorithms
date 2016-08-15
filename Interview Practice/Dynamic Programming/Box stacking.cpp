#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
class Box{
public:
    int w, d, h, index;
    Box(){
        w = -1;
        d = -1;
        h = -1;
        index = -1;
    }

    Box(int w, int d, int h, int index){
        this->w = w;
        this->d = d;
        this->h = h;
        this->index = index;
    }

    int volume() const{
        return this->w*this->d*this->h;
    }

    bool operator<(const Box &A) const{
        if(this->volume() < A.volume())
            return true;
        return false;
    }

    bool operator>(const Box &A) const{
        if(this->volume() > A.volume())
            return true;
        return false;
    }

    bool operator==(const Box &A) const{
        if(this->w == A.w && this->d == A.d && this->h == A.h)
            return true;
        return false;
    }

    friend ostream& operator<<(ostream& os, const Box &box){
        os << box.index << ")  width: " << box.w << " depth: " << box.d << " height: " << box.h << "\t\tVolume: " << box.volume();
        return os;
    }
};

int max(int a, int b){
    return a>b ? a:b ;
}

int boxStacking(vector<Box> &boxes){
    int i,j;
    const int N = boxes.size();
    int* opt = new int[N];
    int* vals = new int[N];
    for(i=0; i<N; i++){
        opt[i] = boxes[i].h; // worst case, this is the only box in the stack.
        vals[i] = -1;
    }
    vals[0] = 0;
    for(i=1; i<N; i++){
        for(j=0; j<i; j++){
            if(boxes[i].w < boxes[j].w && boxes[i].d < boxes[j].d && boxes[i].index !=boxes[j].index) // We can stack the ith box on top of the jth
                if(opt[j]+boxes[i].h > opt[i]){
                    opt[i] = max(opt[i], opt[j]+boxes[i].h);
                    vals[i] = j;
                }
        }
    }

    i=N-1;


    int maxVal = -1;
    int maxValIndex = -1;
    for(i=0; i<N; i++){
        if(opt[i] > maxVal){
            maxVal = max(maxVal, opt[i]);
            maxValIndex = i;
        }
    }
    i = maxValIndex;
    cout<<"\nBoxes:";
    while(i>0){
        cout<<"\n"<<boxes[i];
        i = vals[i];
        if(i==0){
            cout<<"\n"<<boxes[i];
            break;
        }
    }

    return maxVal;
}


void printBoxes(vector<Box> &boxes){
    vector<Box>::iterator iter;
    cout<<endl;
    for(iter=boxes.begin(); iter!=boxes.end(); iter++){
        cout<<"\n"<<(*iter);
    }
    cout<<endl;
}


void addAllRotations(vector<Box> &boxes){
    int len = boxes.size();
    int i,j;
    for(i=0; i<len; i++){
        const Box t = boxes[i];
        // boxes.push_back(*(new Box(t.w, t.d, t.h, t.index))); // this is
        boxes.push_back(*(new Box(t.w, t.h, t.d, t.index)));
        boxes.push_back(*(new Box(t.d, t.w, t.h, t.index)));
        boxes.push_back(*(new Box(t.d, t.h, t.w, t.index)));
        boxes.push_back(*(new Box(t.h, t.d, t.w, t.index)));
        boxes.push_back(*(new Box(t.h, t.w, t.d, t.index)));
    }
}


int main(){
    // Box a(1,2,3);
    // Box b(2,3,4);
    // Box c(4,3,1);
    // Box d(1,2,3);
    // cout<<(a>b)<<endl;
    // cout<<(b>c)<<endl;
    // cout<<(a==d)<<endl;
    // cout<<(a==b)<<endl;
    vector<Box> boxes;
    boxes.push_back(*(new Box(1, 2, 3, 1)));
    boxes.push_back(*(new Box(4, 5, 6, 2)));
    boxes.push_back(*(new Box(2, 2, 1, 3)));
    boxes.push_back(*(new Box(7, 2, 3, 4)));
    // cout<<"\nCurrent boxes: ";
    // printBoxes(boxes);

    addAllRotations(boxes);
    sort(boxes.rbegin(), boxes.rend()); // NOTE: reverse iterators here.
    cout<<"\nBoxes after rotation: ";
    printBoxes(boxes);

    cout<<"\nMaximum height of stack: "<<boxStacking(boxes);

    cout<<endl;
    return 0;
}
