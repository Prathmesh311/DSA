class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
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
