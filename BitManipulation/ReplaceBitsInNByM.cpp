#include<iostream>
#include<vector>
using namespace std;



int clearBitsInRange(int n, int i, int j){
    int ones = ~0;
    int a = ones << j+1;
    int b = (1<<i) - 1;        //clearing bits from left till i
    int mask = a | b;
    n = n & mask;
    return n;
}

int clearBitsInN(int n, int m, int i, int j){
    n = clearBitsInRange(n, i, j);
    int ans = n | (m<<i);
    return ans;
}


int main(){  
    int n = 31;
    int m = 2;
    int i, j;
    cin>>i>>j;
    //cin>>j;

    cout<<clearBitsInN(n, m, i, j);

    return 0;
}