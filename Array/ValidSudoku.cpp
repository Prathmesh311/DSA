class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, set<char>> rows;
        map<char, set<char>> cols;
        map<string, set<char>> squares;

        for(int r=0; r < board.size(); r++){
            for(int c=0; c < board[0].size(); c++){
                if(board[r][c] == '.'){
                    continue;
                }

                string squareKey = to_string(int(r)/3) + to_string(int(c)/3);  //creating key for 3*3 square
                
                if(rows[r].find(board[r][c]) != rows[r].end() || 
                    cols[c].find(board[r][c]) != cols[c].end() ||
                    squares[squareKey].find(board[r][c]) != squares[squareKey].end()){  //checking if num is present in previously in row, col or 3*3 square
                    return false;
                }

                rows[r].insert(board[r][c]);                 //adding new number to row, col, and 3*3 square
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }

        return true;
    }
};
