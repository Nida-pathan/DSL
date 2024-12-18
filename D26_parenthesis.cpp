#include<iostream>
#define size 10
using namespace std;
class stackexp{
    int top;
    char stk[size];
    public:
    stackexp():top(-1){}
    void push(char x){
        if(!isFull()){
            top++;
            stk[top]=x;
        }
        else
        cout<<"Stack is overflow."<<endl;
    }
    char pop(){
        if(!isEmpty()){
            char s=stk[top];
            top--;
            return s;
        }
        else{
            cout<<"Stack is underflow."<<endl;
            return '\0';
        }
    }
    int isFull(){
        return top==size-1;
    }
    int isEmpty(){
        return top==-1;
    }
};
int matchingPair(char open, char close){
    return (open=='(' && close==')')||(open=='[' && close==']')||(open=='{' && close=='}');
}
int main(){
    stackexp s1;
    char exp[20], ch;
    int i=0;
    cout<<"\n\t\tParenthesis Checker!!!\n";
    cout<<"Enter expression: ";
    cin>>exp;
    if(exp[0]==')' || exp[0]==']' || exp[0]=='}'){
        cout<<"Invalid expression."<<endl;
        return 0;
    }
    else{
        while(exp[i]!='\0'){
            ch=exp[i];
            if(ch=='(' || ch=='[' || ch=='{'){
                s1.push(ch);
            }
            else if(ch==')' || ch=='}' || ch==']'){
                if(s1.isEmpty() || !matchingPair(s1.pop(), ch)){
                    cout<<"Expression is not well parenthesized."<<endl;
                    return 0;
                }
            }
            i++;
        }
    }
    if(!s1.isEmpty()){
        cout<<"Expression is not well-parenthesized."<<endl;
    }
    else{
        cout<<"Expression is well-parenthesized."<<endl;
    }
    return 0;
}
