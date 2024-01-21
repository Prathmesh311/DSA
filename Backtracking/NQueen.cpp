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

//Easy to implement method
class Solution {
public:
    void NQueens(vector<vector<string>> board, vector<vector<string>> &comb, set<int> posDiag, set<int> negDiag,vector<int> &cols, int row){
        if(row >= board.size()){
            vector<string> v;
            for(int i=0; i < board.size(); i++){
                string str = "";
                for(int j=0; j < board[0].size(); j++){
                    str += board[i][j];
                }
                v.push_back(str);
            }
            comb.push_back(v);
        }

        for(int i=0; i < board[0].size(); i++){
            if(cols[i] == 0 && posDiag.find(row+i) == posDiag.end() && negDiag.find(row-i) == negDiag.end()){

                cols[i] = 1;
                board[row][i] = "Q";
                posDiag.insert(row+i);
                negDiag.insert(row-i);

                NQueens(board, comb, posDiag, negDiag, cols, row+1);
                
                cols[i] = 0;
                board[row][i] = ".";
                posDiag.erase(row+i);
                negDiag.erase(row-i);
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> comb;
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<int> cols(n, 0);
        set<int> posDiag;
        set<int> negDiag;
    
        

        NQueens(board, comb, posDiag, negDiag, cols, 0);
        return comb;
    }
};

int main() {
   int board[10][10] = {0};

   nQueen(board, 0, 4);
}
