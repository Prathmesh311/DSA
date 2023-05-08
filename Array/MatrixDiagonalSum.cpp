class Solution {
public:
    int firstDiagonal(vector<vector<int>>& mat, vector<vector<int>>& visited, int row, int col){
        if(row >= mat.size() || col >= mat.size()){
            return 0;
        }

        int sum;
        if(visited[row][col] == 0){
            sum = firstDiagonal(mat, visited, row+1, col+1) + mat[row][col];
        }
        else{
            sum = firstDiagonal(mat, visited, row+1, col+1);
        }

        visited[row][col] = 1;
        return sum;
    }

    int secondDiagonal(vector<vector<int>>& mat, vector<vector<int>>& visited, int row, int col){
        if(row >= mat.size() || col < 0){
            return 0;
        }

        int sum;
        if(visited[row][col] == 0){
            sum = secondDiagonal(mat, visited, row+1, col-1) + mat[row][col];
        }
        else{
            sum = secondDiagonal(mat, visited, row+1, col-1);
        }

        visited[row][col] = 1;
        return sum;
    }

    int diagonalSum(vector<vector<int>>& mat) {
        vector<vector<int>> visited(100, vector<int>(100, 0));

        return firstDiagonal(mat, visited, 0, 0) + secondDiagonal(mat, visited, 0, mat.size()-1);
    }
};
