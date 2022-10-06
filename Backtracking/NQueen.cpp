#include <iostream>
using namespace std;

bool canPlace(int board[][10], int i, int j, int n){
    //checking top
    for(int k=0; k < i; k++){
        if(board[k][j] == 1){
            return false;
        }
    }

    //checking left diagonal
    while(i >=0 && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }

    //checking right diagonal
    while(i >=0 && j < n){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }

    return true;
}

bool nQueen(int board[][10], int i, int n){
    //Base case
    if(i == n){
        //Print board
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                cout<<board[row][col]<< " ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }


    //Recursive case
    for(int j=0; j < n; j++){
        if(canPlace(board, i, j, n)){
            board[i][j] = 1;
            bool placed = nQueen(board, i+1, n);

            if(placed){
                return true;
            }
        }

        //Backtracking
        board[i][j] = 0;
        
    }

    return false;

}

int main() {
   int board[10][10] = {0};

   nQueen(board, 0, 4);
}