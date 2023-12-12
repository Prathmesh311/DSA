class Solution {
public:
    int maxArea(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return 0;
        }

        if(grid[row][col] == 0){
            return 0;
        }

        grid[row][col] = 0;
        
        int down = maxArea(grid, row+1, col);
        int right = maxArea(grid,row, col+1);
        int up = maxArea(grid, row-1, col);
        int left = maxArea(grid,  row, col-1);

        return down + up + left + right + 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;

        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                   maxSize = max(maxSize, maxArea(grid,  i, j));
                }
            }
        }

        return maxSize;
    }
};
