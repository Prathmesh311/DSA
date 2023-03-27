class Solution {
public:
    int minPath(vector<vector<int>>& grid, int dp[][201], int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return INT_MAX;
        }

        if(dp[row][col] != 0){
            return dp[row][col];
        }

        int right = minPath(grid, dp, row, col+1);
        int down = minPath(grid, dp, row+1, col);

        if(right == INT_MAX && down == INT_MAX){
            return grid[row][col];
        }

        dp[row][col] = min(right, down) + grid[row][col];

        return dp[row][col];
    }

    
    int minPathSum(vector<vector<int>>& grid) {
        //Recursive method
        //int dp[201][201] = {0};
        //return minPath(grid, dp, 0, 0);
        
        //Tabular Method
        int rows = grid.size();
        int cols = grid[0].size();
        
        int cost[200][200] = {INT_MAX};
        
        for(int i=0; i < rows; i++){
            for( int j=0; j < cols; j++){
                
                if(i == 0 && j == 0){
                    cost[i][j] = grid[i][j];
                }
                else if(i == 0){
                    cost[i][j] = grid[i][j] + cost[i][j-1];  //1st row
                }
                else if(j == 0){
                    cost[i][j] = grid[i][j] + cost[i-1][j];  //1st col
                }
                else{
                    cost[i][j] = min(cost[i-1][j], cost[i][j-1]) + grid[i][j];
                }
            }
        }
        return cost[rows-1][cols-1];
    }
};
