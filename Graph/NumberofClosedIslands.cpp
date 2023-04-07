class Solution {
public:
    bool traverseIsland(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return false;
        }

        if(grid[row][col] == 1){
            return true;
        }

        grid[row][col] = 1;
        bool left  = traverseIsland(grid,  row, col-1);
        bool right = traverseIsland(grid,  row, col+1);
        bool up    = traverseIsland(grid,  row-1, col);
        bool down  = traverseIsland(grid,  row+1, col);

        if(left && right && up && down){
            return true;
        }
        
        return false;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int totalClosedIslands= 0;

        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    if(traverseIsland(grid, i, j)){
                        totalClosedIslands++;
                    }
                }
            }
        }
        return totalClosedIslands;
    }
};
