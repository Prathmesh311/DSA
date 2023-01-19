#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){

    for(int i=0; i < n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}
void reverseStack(stack<int> &s1){
    stack<int> helperStack;

    int n = s1.size();

    for(int i=0; i < n; i++){
        //Pick the top element of stack and save in x
        int x = s1.top();
        s1.pop();

        //Transfer n-i-1 elements to to helper stack
        transfer(s1, helperStack, n-i-1);

        //Push x to s1
        s1.push(x);

        //Transfer n-i-1 elements to s1 from helper stack
        transfer(helperStack, s1, n-i-1);
    }
}

int main(){
    stack<int> s;

    for(int i=1; i < 6; i++){
        s.push(i);
    }

    reverseStack(s);

    while (!s.empty())
    {
       cout<<s.top()<<" ";
       s.pop();
    }
    

    return 0;
}