#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Source: http://stackoverflow.com/questions/236129/split-a-string-in-c/7408245#7408245
vector<string> split(string &text, string separator){
    vector<string> tokens;
    int start=0, end=0;
    while((end = text.find(separator, start)) != string::npos ){
        tokens.push_back(text.substr(start, end-start));
        start = end+separator.size();
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

int main(){
    string str = "this is lol an example lol can I have a lol?";
    vector<string> splitted = split(str, "lol");
    for(int i=0; i<splitted.size(); i++){
        cout<<"\n"<<splitted[i];
    }
    cout<<endl;
    return 0;
}
