class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid, vector<vector<int>> &dp, int row, int col){
        if(row < 0 || col < 0){
            return 0;
        }

        if(grid[row][col] == 1){
            return  dp[row][col] = 0;
        }

        if(row == 0 && col == 0){
            return dp[row][col] = 1;
        }

        if(dp[row][col] != 0){
            return dp[row][col];
        }

        int left = uniquePaths(grid, dp, row, col-1);
        int top  = uniquePaths(grid, dp, row-1, col);

        dp[row][col] = left + top;

        return dp[row][col];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //vector<vector<int>> dp(101, vector<int>(101, 0));
        //return uniquePaths(obstacleGrid, dp, obstacleGrid.size()-1, obstacleGrid[0].size()-1);
        
        
        int dp[100][100] = {0};
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        for(int i=0; i < m; i++){
            for( int j=0; j < n; j++){
                
                if(i==0 && j==0){
                    if(obstacleGrid[i][j] != 1){
                        dp[i][j] = 1;
                    }
                    else{
                        return 0;
                    }
                }
                
                else if(i == 0){
                    if(dp[i][j-1] != 0 && obstacleGrid[i][j] != 1){
                        dp[i][j] = 1;
                    }else{
                         dp[i][j] = 0;
                    }
                }
                else if(j == 0){
                    if(dp[i-1][j] != 0 && obstacleGrid[i][j] != 1){
                        dp[i][j] = 1;
                    }else{
                         dp[i][j] = 0;
                    }
                }
                else{
                    if(obstacleGrid[i][j] != 1){
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
        } 
        
        return dp[m-1][n-1];
    }
};
