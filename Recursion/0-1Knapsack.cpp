#include<iostream>
using namespace std;

int maxProfit=0;
int kanpsack(int bagsize, int profit, int *weights, int prices[], int i){
    //Base case
    if(bagsize == 0 || i == 4){
        return  0;
    }

    //Recursive case
    int including = 0;
    int excluding = 0;
    if(bagsize > 0){
        if( bagsize-weights[i] >=0){
            including = prices[i] + kanpsack(bagsize - weights[i], profit, weights, prices, i+1);
        }
        excluding = kanpsack(bagsize, profit, weights, weights, i+1);
       
    }

    return max(including, excluding);
}

int main(){
   
    int bagsize = 4;
    int weights[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};

    
    cout<<kanpsack(bagsize, 0, weights, prices, 0);
  
    return 0;
}