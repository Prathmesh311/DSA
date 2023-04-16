class Solution {
public:
    bool isValid(int i,int j,int m,int n)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> direc = {{0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
        queue<pair<int, int>> q; 

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return -1;
        }
        if(m==1 && n==1){
            return 1;
        }

        q.push({0, 0});
        visited[0][0] = 1;

        while(!q.empty()){
            pair<int, int> node = q.front();

            int currRow = node.first;
            int currCol = node.second;
            
            q.pop();
            visited[currRow][currCol] = 1;

            for(auto x : direc){
                int nextRow = currRow + x[0];
                int nextCol = currCol + x[1];
                if(isValid(nextRow, nextCol, m, n) && visited[nextRow][nextCol] != 1 && grid[nextRow][nextCol] == 0){
                    
                    grid[nextRow][nextCol] = grid[currRow][currCol] + 1;
                    q.push({nextRow, nextCol});
                }
            }
        }

        return grid[m-1][n-1] == 0 ? -1:  grid[m-1][n-1]+1;
        
    }
};
