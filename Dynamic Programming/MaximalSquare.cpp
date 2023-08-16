class Solution {
public:

    int solve(vector<vector<char>>& matrix, int i, int j, int &maxSquare, vector<vector<int>> &dp){
        if(i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(matrix, i, j+1, maxSquare, dp);
        int diagonal = solve(matrix, i+1, j+1, maxSquare, dp);
        int bottom = solve(matrix, i+1, j, maxSquare, dp);

        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min(right, min(diagonal, bottom));
            maxSquare = max(maxSquare, dp[i][j]*dp[i][j]);
            return dp[i][j];
        }else{
            return dp[i][j] = 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int maxSquare = 0;

        int num = solve(matrix, 0, 0, maxSquare, dp);
        return maxSquare;
    }
};
