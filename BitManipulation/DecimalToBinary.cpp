#include<iostream>
#include<vector>
using namespace std;

int decimalToBinary(int n){
    int ans = 0;
    int power = 1;
    
    while(n > 0){
        ans += (n&1) * power;

        power = power*10;
        n = n>>1;
    }
    return ans;
}


int main(){  
    int n;
    cin>>n;

    cout<<decimalToBinary(n);


    return 0;
}