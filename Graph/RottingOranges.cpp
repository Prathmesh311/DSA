class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<pair<int, int>, int>> &q){
        vector<pair<int, int>> direc{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int steps = 0;

        while(!q.empty()){
            pair<pair<int, int>, int> p = q.front();
            int row = p.first.first;
            int col = p.first.second;
            int level = p.second;
            q.pop();

            for(auto p : direc){
                int nextRow = row + p.first;
                int nextCol = col + p.second;
                
                if(!(nextRow < 0 || nextCol < 0 || nextRow >= grid.size() || nextCol >= grid[0].size()) && grid[nextRow][nextCol] == 1){
                    q.push({{nextRow, nextCol}, level+1});
                    grid[nextRow][nextCol] = 2;
                    steps = max(steps, level+1);
                }
            }
        }

        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return steps;

    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }

        return bfs(grid, q);
    }
};
