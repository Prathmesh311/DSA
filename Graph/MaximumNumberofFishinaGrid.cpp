class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return 0;
        }

        if(visited[row][col] == 1){
            return 0;
        }

        if(grid[row][col] == 0){
            visited[row][col] = 1;
            return 0;
        }

        visited[row][col] = 1;

        return dfs(grid, visited, row+1, col) + 
                dfs(grid, visited, row-1, col) + 
                dfs(grid, visited, row, col+1) + 
                dfs(grid, visited, row, col-1) + grid[row][col];
    }

    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size()+1, vector<int>(grid[0].size()+1, 0));
        int maxFish = 0;

        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(visited[i][j] == 0){
                    maxFish = max(maxFish, dfs(grid, visited, i, j));
                }
            }
        }

        return maxFish;
    }
};
