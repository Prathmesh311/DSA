#include<iostream>
using namespace std;

void permutations(char *in, int i){
    //Base case
    if(in[i] == '\0'){
        cout<<in<<" ";
        return;
    }

    //Recursive case
    for(int j=i; in[j] != '\0'; j++){
        swap(in[i], in[j]);
        permutations(in, i+1);

        //Backtracking
        swap(in[i], in[j]);
    }
}

int main(){
    char in[100];

    cin>>in;

    permutations(in, 0);
   
    return 0;
}