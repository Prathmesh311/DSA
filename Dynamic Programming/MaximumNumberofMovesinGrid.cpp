class Solution {
public:
    int traverse(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col, int pastValue){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return 0;
        }
        
        int currValue = grid[row][col];
        if(currValue <= pastValue){
            return 0;
        }
        
        if(dp[row][col] != 0){
            return dp[row][col];
        }
        
        int upDiagonal = traverse(grid, dp, row-1, col+1, currValue);
        int right      = traverse(grid, dp, row, col+1, currValue);
        int downDiagonal=traverse(grid, dp, row+1, col+1, currValue);
        
        int maxMoves = max(upDiagonal, max(right, downDiagonal)) + 1;
        
        dp[row][col] = maxMoves;
        return maxMoves;
        
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(1001, vector<int>(1001, 0));
        int ans = 0;
        for(int i=0; i < grid.size(); i++){
            ans = max(ans, traverse(grid, dp, i, 0, grid[i][0]-1));
        }
        
        return ans-1;
    }
};
