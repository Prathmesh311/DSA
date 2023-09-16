class Solution {
public:
    bool canPlace(vector<vector<char>> &board, char ch, int row, int col){
        for(int i=0; i < board.size(); i++){
           if(board[i][col] == ch || board[row][i] == ch){
                return false;
            }
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch){
                return false;
            }
        }
        return true;
    }

    bool sudokuSolver(vector<vector<char>> &board){

        for(int i = 0; i < board.size(); i++){
            for(int j= 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){

                    for(int num = 1; num <= 9; num++){
                        char ch = '0' + num;
                        
                      if(canPlace(board, ch, i, j)){
                            board[i][j] = ch;
                            if(sudokuSolver(board)){
                                return true;
                            }else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int ans = sudokuSolver(board);
    }
};
