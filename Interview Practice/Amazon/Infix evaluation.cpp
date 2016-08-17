#include<stack>
#include<iostream>
#include<string>
using namespace std;

int priority(char op){
    switch(op){
        case '+': return 1;
        case '-': return 2;
        case '*': return 3;
        case '/': return 4;
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

int infixEval(string expr){
    stack<int> values;
    stack<char> operators;
    int val1, val2;
    char current;
    for(int i=0; i<expr.length(); i++){
        current = expr.at(i);
        // cout<<"\n\n\nCurrent char: "<<current;
        if(priority(current) == -1)
        values.push(current - '0');
        else{
            while(!operators.empty() && priority(current) <= priority(operators.top())){
                val2 = values.top();
                values.pop();
                val1 = values.top();
                values.pop();
                values.push(eval(val1, val2, operators.top()));
                operators.pop();
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
        val2 = values.top();
        values.pop();
        val1 = values.top();
        values.pop();
        values.push(eval(val1, val2, operators.top()));
        operators.pop();
        // cout<<"\nValues:";
        // printStack(values);
        // cout<<"\nOperators:";
        // printStack(operators);
    }
    return values.top();
}



int main(){
    string e = "4/2*6/2";
    cout<<"\n\nFinal value: "<<infixEval(e);

    cout<<endl;
    return 0;
}
