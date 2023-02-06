#include<iostream>
#include<vector>
using namespace std;

bool isOdd(int n){
    return (n & 1);     //and to last bit - returns 1 if odd
}

int getBit(int n, int i){
    int mask = (1 << i);
    int bit = (n & mask) > 0 ? 1 : 0;
    return bit;

}

int setBit(int n, int i){
    int mask = (1 << i);
    return (n | mask);
}

void clearBit(int &n, int i){
    int mask = ~(1<<i);
    n = n & mask;
}

void updateBit(int &n, int i, int v){
    int mask = ~(1<<i);
    int cleared_n = n & mask;
    n = cleared_n | (v<<i);
}

int main(){  
    int n = 5;
    int i;
    cin>>i;

    cout<<getBit(n, i)<<endl;
    cout<<setBit(n, i)<<endl;

    clearBit(n, i);
    cout<<n<<endl;

    updateBit(n, 2, 0);
    updateBit(n, 3, 1);
    cout<<n<<endl;;


    return 0;
}