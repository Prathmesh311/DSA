class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(10, 0));
        vector<vector<int>> cols(9, vector<int>(10, 0));
        vector<vector<vector<int>>> blocks(3, vector<vector<int>>(3, vector<int>(10, 0)));

        
        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }

                int currNum = board[i][j] - '0';
                
                if(rows[i][currNum] || cols[j][currNum] || blocks[i/3][j/3][currNum]){
                    return false;
                }else{
                    rows[i][currNum] = 1;
                    cols[j][currNum] = 1;
                    blocks[i/3][j/3][currNum] = 1;
                }
            }
        }

        return true;
    }
};
