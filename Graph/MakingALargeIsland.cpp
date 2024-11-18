/*
0 0 0 0 0
2 2 0 0 3
2 2 0 3 3
0 0 0 0 0


o/p = 8

time = O(N^2)
space = O(N)

*/

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int currIsland){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()){
            return 0;
        }

        if(grid[row][col] != 1){
            return 0;
        }

        grid[row][col] = currIsland;

        return dfs(grid, row+1, col, currIsland) + dfs(grid, row-1, col, currIsland) +
                dfs(grid, row, col-1, currIsland) + dfs(grid, row, col+1, currIsland) + 1;
    }

    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> islandSize;
        vector<vector<int>> direc = {{0,1}, {1,0}, {-1, 0}, {0, -1}};

        int currIsland = 2;

        int largestIsland = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int size = dfs(grid, i, j, currIsland);
                    islandSize[currIsland] = size;
                    largestIsland = max(largestIsland, size);
                    currIsland++;
                }
            }
        }

        
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    int sum = 1;
                    unordered_set<int> visited;
                    for(auto d : direc){
                        int nextRow = i + d[0];
                        int nextCol = j + d[1];

                        if(nextRow >= 0 && nextCol >= 0 && nextRow < grid.size() && nextCol < grid[0].size()){
                            int currIsland = grid[nextRow][nextCol];
                            if(visited.find(currIsland) != visited.end()){
                                continue;
                            }
                            sum += islandSize[currIsland];
                            visited.insert(currIsland);
                        }
                        largestIsland = max(largestIsland, sum);
                    }
                }
            }
        }

        return largestIsland;
    }
};
