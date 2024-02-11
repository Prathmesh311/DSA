class Solution {
public:
    //Dijktra's Algo
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> time(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        queue<pair<int, int>> q;


        time[0][0] = grid[0][0];
        q.push({0, 0});


        vector<vector<int>> directions = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;

            for(auto v : directions){
                int nextRow = row + v[0];
                int nextCol = col + v[1];

                if(nextRow < grid.size() && nextCol < grid[0].size() && nextRow >= 0 && nextCol >= 0 &&
                    time[nextRow][nextCol] > time[row][col]){
                        time[nextRow][nextCol] = max(time[row][col], grid[nextRow][nextCol]);
                        q.push({nextRow, nextCol});
                    }
            }
        }

        return time[grid.size()-1][grid[0].size()-1];
    }
};
