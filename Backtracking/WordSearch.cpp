class Solution {
public:

    bool traversal(vector<vector<char>>& board, vector<vector<int>> &visited, string word, int index, int row, int col){
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()){
            return false;
        }

        if(visited[row][col] == 1){
            return false;
        }

        if(index == word.size()-1 && board[row][col] == word[index]){
            return true;
        }

        visited[row][col] = 1;

        if(board[row][col] == word[index]){
            bool isPresent =  traversal(board, visited, word, index+1, row+1, col) || 
                                traversal(board, visited, word, index+1, row-1, col) ||
                                traversal(board, visited, word, index+1, row, col+1) ||
                                traversal(board, visited, word, index+1, row, col-1);

            visited[row][col] = 0;
            return isPresent;

        }

        visited[row][col] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));


        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && traversal(board, visited, word, 0, i, j)){
                    return true;
                }
            }
        }

        return false;
    }
};
