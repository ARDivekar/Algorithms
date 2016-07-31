/*
http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
Given a string, find the length of the longest substring without repeating
characters. For example, the longest substrings without repeating characters for
“ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. For “BBBB” the longest
substring is “B”, with length 1. For “GEEKSFORGEEKS”, there are two longest
substrings shown in the below diagrams, with length 7.
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int longestNonRepeatingSubstring(string str){
    // returns length of longest non repeating substring:
    int i;
    int* charIndex = new int[256];
    for(i=0; i<256; i++)
        charIndex[i]=-1;
    int maxLen = 1;
    int curLen = 0;
    int start = 0;
    int maxStart = 0;
    for(i=0; i<str.size(); i++){
        char currentChar = str.at(i);
        if(charIndex[currentChar]==-1){
            charIndex[currentChar]=i;
            curLen+=1;
        }
        else if(i-charIndex[currentChar] <= curLen){ // char is seen before, and it lies inside the current window.
            curLen = curLen - charIndex[currentChar];
            start = charIndex[currentChar]+1;
            charIndex[currentChar] = i;
        }
        if(maxLen < curLen){
            maxLen = curLen;
            maxStart = start;
        }
        cout<<"\ni : "<<i<<"    currentChar: "<<currentChar<<"    curLen: "<<curLen<<"    maxLen: "<<maxLen<<"    substr: "<<str.substr(maxStart, maxLen);


    }
    return maxLen;
}

int main(){
    cout<<"\n"<<longestNonRepeatingSubstring("AUDACIOUS");
    cout<<endl;
    return 0;
}
