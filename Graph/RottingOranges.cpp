class Solution {
public:
    bool isValid(int row, int col, int m, int n){
        if(row >= m || col >= n || row < 0 || col < 0){
            return false;
        }
        return true;
    }
    
    void makeRotten(vector<vector<int>>& grid, vector<vector<int>> &time, queue<pair<int, int>> q, int &timeNeeded){
        while(!q.empty()){
            pair<int, int> p = q.front();
            int currRow = p.first;
            int currCol = p.second;
            q.pop();

            grid[currRow][currCol] = 2;

            vector<vector<int>> direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for(vector<int> path: direc){
                int nextRow = currRow + path[0];
                int nextCol = currCol + path[1];

                if(isValid(nextRow, nextCol, grid.size(), grid[0].size()) && grid[nextRow][nextCol] == 1 && time[nextRow][nextCol] == -1){
                    q.push({nextRow, nextCol});
                    time[nextRow][nextCol] = time[currRow][currCol] + 1;
                    timeNeeded = max(timeNeeded, time[nextRow][nextCol]);
                }
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> time(m, vector<int>(n, -1));

        int timeNeeded = 0;
        for(int i=0; i < m; i++){                      //finding all rotten oranges and adding it's location in q
            for(int j=0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    time[i][j] = 0;
                }
            }
        }
        makeRotten(grid, time, q, timeNeeded);         //start rotting connected oranges using bfs

        for(int i=0; i < m; i++){                      //If some oranges left then return -1;
            for(int j=0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return timeNeeded;    
    }
};
