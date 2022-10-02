#include<iostream>
using namespace std;

char alpha[] = {' ','a', 'b', 'c', 'd','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void generateString(int *nums, int n, string str, int i){
    //Base case
    if(i >= n){
        cout<<str<<endl;;
        return;
    }

    //Recursive case
    //Taking 2 numbers below 26 at a time from input
    if(nums[i]*10 + nums[i+1] <= 26){
        generateString(nums, n, str + alpha[nums[i]*10 + nums[i+1]], i+2);
    }

    generateString(nums, n, str + alpha[nums[i]], i+1);
}

int main(){
   int nums[] = {1, 2, 3, 1, 2, 6};
    int n = sizeof(nums)/sizeof(int);
   generateString(nums, n,"", 0);

   
   
  
return 0;
}