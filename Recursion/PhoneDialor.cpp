#include<iostream>
using namespace std;

char keypad[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void phoneDialor(char *in, char *out, int i, int j){
    //Base case
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }

    //Recursive case
    int digit = in[i] - '0';
    if(digit == 0 || digit==1){
        phoneDialor(in, out, i+1, j);
    }
    for(int k=0; keypad[digit][k] != '\0'; k++){
        out[j] = keypad[digit][k];
        phoneDialor(in, out, i+1, j+1);
    }

}

int main(){
   
    char in[100];
    char out[100];

    cin>>in; 
    phoneDialor(in, out, 0, 0);
  
    return 0;
}