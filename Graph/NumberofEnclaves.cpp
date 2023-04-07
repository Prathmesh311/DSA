class Solution {
public:
    int traverseIsland(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return -1;
        }

        if(grid[row][col] == 0){
            return 0;
        }

        grid[row][col] = 0;
        int left  = traverseIsland(grid,  row, col-1);
        int right = traverseIsland(grid,  row, col+1);
        int up    = traverseIsland(grid,  row-1, col);
        int down  = traverseIsland(grid,  row+1, col);

        if(left >= 0 && right >= 0 && up >= 0 && down >= 0){
            return left + right + up + down + 1;
        }
        
        return -1;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int totalClosedIslands= 0;

        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){   
                    int currMoves = traverseIsland(grid, i, j);
                    if(currMoves != -1){
                        totalClosedIslands += currMoves;
                    }
                }
            }
        }
        return totalClosedIslands;
    }
};
