class Solution {
public:
    int MOD = 1000000007;
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col, int prevNum){
        if(row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size()){
            return 0;
        }   

        int currNum = matrix[row][col];
        
        if(prevNum >= currNum){
            return 0;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int left = dfs(matrix, dp, row, col-1, currNum);
        int right = dfs(matrix, dp, row, col+1, currNum);
        int up = dfs(matrix, dp, row-1, col, currNum);
        int down = dfs(matrix, dp, row+1, col, currNum);

        return dp[row][col] = (1 + left + right + up + down) % MOD;
        
    }

    int countPaths(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        int numIncreasingPaths = 0;
        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[0].size(); j++){
                numIncreasingPaths = (numIncreasingPaths + dfs(matrix, dp, i, j, -1)) % MOD;
            }
        }

        return numIncreasingPaths;
    }
};
