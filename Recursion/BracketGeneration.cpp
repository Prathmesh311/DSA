#include<iostream>
using namespace std;

void generateBracket(int size, int opening, int closing, char *brackets, int i){
    //Base case
    if(i >= size){
        brackets[i] = '\0';
        cout<<brackets<< endl;
        return;
    }

    //Recursive case

    if(opening > 0){
        brackets[i] = '(';
        generateBracket(size, opening-1, closing, brackets, i+1);
    }
    if(closing > 0 && closing > opening){
        brackets[i] = ')';
        generateBracket(size, opening, closing-1, brackets, i+1);
    }

}

int main(){
   
    int n;
    char brackets[100];

    cin>>n;
    generateBracket(2*n, n, n, brackets, 0);
  
    return 0;
}