#include<iostream>
using namespace std;

int coinChange(int coins[], int amount, int size){

    int counter = 0;

    while(amount > 0){

        for(int i=1; i< size; i++){
            if(coins[i] > amount){
                amount = amount - coins[i-1];
                counter++;
                break;
            }
        }
    }

    return counter;
}

int main(){
    int n;
    cin>>n;

    int coins[] = {1,2,5,10,20,50,100,200,500,1000,2000};
    int size = sizeof(coins)/sizeof(int);


    int numOfCoins = coinChange(coins, n, size);
    cout<<numOfCoins;

    return 0;
}