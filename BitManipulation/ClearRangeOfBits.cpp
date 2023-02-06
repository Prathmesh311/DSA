#include<iostream>
#include<vector>
using namespace std;


int clearlastIBits(int n, int i){
    int mask = (-1<<i);
    n = n & mask;
    return n;
}

int clearBitsInRange(int n, int i, int j){
    int ones = ~0;
    int a = ones << j+1;
    int b = (1<<i) - 1;        //clearing bits from left till i
    int mask = a | b;
    n = n & mask;
    return n;
}


int main(){  
    int n = 31;
    int i, j;
    cin>>i;
    cin>>j;

    cout<<clearlastIBits(n, i)<<endl;
    cout<<clearBitsInRange(n, i, j)<<endl;
   


    return 0;
}