class Solution {
public:
    bool canPlace(vector<vector<int>> &board, int n, int row, int col){
        int currRow = row;
        int currCol = col;

        while(currRow >= 0){
            if(board[currRow][currCol] == 1){
                return false;
            }
            currRow--;
        }

        currRow = row;
        while(currRow >= 0 && currCol >= 0){
            if(board[currRow][currCol] == 1){
                return false;
            }
            currRow--;
            currCol--;
        }

        currRow = row;
        currCol = col;
        while(currRow >= 0 && currCol < n){
            if(board[currRow][currCol] == 1){
                return false;
            }
            currRow--;
            currCol++;
        }
        
        return true;
    }

    void NQueens(vector<vector<int>> &board, int n, int row, int &totalNQueens){
        if(row == n){
            totalNQueens += 1;
            return;
        }

        for(int col = 0; col < n; col++){
            if(canPlace(board, n, row, col)){

                board[row][col] = 1;
                NQueens(board, n, row+1, totalNQueens);
                board[row][col] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        int totalNQueens = 0;

        NQueens(board, n, 0, totalNQueens);
        return totalNQueens;
    }
};
