#include<iostream>
using namespace std;

int ladderProblem(int n){
    //Base case
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }

    //Recursive case
    return ladderProblem(n-1) + ladderProblem(n-2) + ladderProblem(n-3);
}

int main(){
    int n;
    cin>>n;

    cout<<ladderProblem(n);
  
    return 0;
}