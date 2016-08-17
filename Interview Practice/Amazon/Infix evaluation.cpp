#include<stack>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int priority(char op){
    switch(op){
        case '+': return 1;
        case '-': return 2;
        case '*': return 3;
        case '/': return 4;
        case '(': return 0;
        case ')': return 0;
        default: return -1;
    }

}

int eval(int a, int b, char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}

template< typename T >
void printStack(stack<T> &a){
    stack<T> b;
    while(!a.empty()){
        cout<<"\n"<<a.top();
        b.push(a.top());
        a.pop();
    }
    cout<<endl;
    while(!b.empty()){
        a.push(b.top());
        b.pop();
    }
}

void popComputePush(stack<int> &values, stack<char> &operators){
    int val2 = values.top();
    // cout<<"\nval2: "<<val2;
    values.pop();
    int val1 = values.top();
    // cout<<"\nval1: "<<val1;
    values.pop();
    values.push(eval(val1, val2, operators.top()));
    operators.pop();
    // cout<<"\nValues:";
    // printStack(values);
    // cout<<"\nOperators:";
    // printStack(operators);
}

int parseNum(string &expr, int &i){
    string num = "";
    while(priority(expr.at(i)) == -1 ){
        num.push_back(expr.at(i));
        i++;
    }
    i--;
    return atoi(num.c_str());
}

int infixEval(string expr){
    stack<int> values;
    stack<char> operators;
    int val1, val2;
    char current;
    for(int i=0; i<expr.length(); i++){
        current = expr.at(i);
        // cout<<"\n\n\nCurrent char: "<<current;
        if(priority(current) == -1){
            values.push(parseNum(expr, i));
        }
        else if(current == '(')
            operators.push(current);
        else if(current == ')'){
            while(!operators.empty() && operators.top()!='('){
                popComputePush(values, operators);
            }
            operators.pop();
        }
        else{
            while(!operators.empty() && priority(current) <= priority(operators.top())){
                popComputePush(values, operators);
            }
            operators.push(current);
        }
        // cout<<"\nValues:";
        // printStack(values);
        // cout<<"\nOperators:";
        // printStack(operators);
    }
    // cout<<"\n\nFinal evaluation: ";
    while(!operators.empty() && values.size()!=1){
        popComputePush(values, operators);
    }
    return values.top();
}



int main(){
    string e = "(333*(1-(6+2)/2))";
    cout<<"\n\nFinal value: "<<infixEval(e);

    cout<<endl;
    return 0;
}
