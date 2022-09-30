#include<iostream>
using namespace std;

void subsequences(char str[], int n, string subset, int i){
    //Base case
    if(i == n){
        cout<<subset<<" ";
        return;
    }

    //Recursive case
    //Including current char
    subsequences(str, n, subset + str[i], i+1);
    //Excluding current char
    subsequences(str, n, subset, i+1);
    
}

int main(){
   char str[] = "abcd";

   int n = sizeof(str)/sizeof(char)-1;

   subsequences(str, n, "", 0);

   
  
return 0;
}