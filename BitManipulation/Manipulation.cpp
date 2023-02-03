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

int main(){  
    int n = 5;
    int i;
    cin>>i;

    cout<<getBit(n, i)<<endl;
    cout<<setBit(n, i)<<endl;


    return 0;
}