class Solution {
public:
    bool subIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col){
        if(row < 0 || col < 0 || row >= grid2.size() || col >= grid2[0].size()){
            return true;
        }

        if(grid2[row][col] == 0){
            return true;
        }

         if(grid2[row][col] == 1 && grid1[row][col] == 0){
            return false;
        }

        grid2[row][col] = 0;
        bool left  = subIsland(grid1, grid2, row, col-1);
        bool right = subIsland(grid1, grid2, row, col+1);
        bool up    = subIsland(grid1, grid2, row-1, col);
        bool down  = subIsland(grid1, grid2, row+1, col);

        if(left && right && up && down){
            return true;
        }
        
        return false;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int totalSubIslands = 0;

        for(int i=0; i < grid2.size(); i++){
            for(int j=0; j < grid2[0].size(); j++){
                if(grid2[i][j] == 1){
                    if(subIsland(grid1, grid2, i, j)){
                        totalSubIslands++;
                    }
                }
            }
        }
        
        return totalSubIslands;
    }
};
