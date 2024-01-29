class Solution {
public:
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

        return dp[row][col] = max(left, max(right, max(up, down))) + 1;
        
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        int maxLen = 0;
        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[0].size(); j++){
                maxLen = max(maxLen, dfs(matrix, dp, i, j, -1));
            }
        }

        return maxLen;
    }
};
