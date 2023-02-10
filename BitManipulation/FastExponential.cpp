#include<iostream>
using namespace std;

int fastExponential(int a, int n){
    int ans = 1;
    
    while(n > 0){
        int last_digit = n&1;
        if(last_digit){
            ans = ans*a;
        }
        a = a*a;
        n = n>>1;
    }
    return ans;
}


int main(){  
    int n, a;
    cin>>a>>n;

    cout<<fastExponential(a, n);


    return 0;
}