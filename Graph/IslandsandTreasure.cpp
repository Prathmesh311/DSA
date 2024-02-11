class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<int>> cost(grid.size());
        queue<pair<int, int>> q;

        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                cost[i].push_back(grid[i][j]);
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;

            for(auto v: directions){
                int nextRow = row + v[0];
                int nextCol = col + v[1];
                int nextCost = grid[row][col] + 1;

                if(nextRow < grid.size() && nextCol <grid[0].size() && nextRow >= 0 && nextCol >= 0 &&
                    grid[nextRow][nextCol] != -1 && grid[nextRow][nextCol] > nextCost){
                        grid[nextRow][nextCol] = nextCost;
                        q.push({nextRow, nextCol});
                    }
            }
        }
    }
};
