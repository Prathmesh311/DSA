class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int maxVal = 0;

        pq.push({grid[0][0], 0, 0});

        vector<vector<int>> direc = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();

            int row = v[1];
            int col = v[2];

            maxVal = max(maxVal, v[0]);
            visited[row][col] = 1;

            if(row == grid.size()-1 && col == grid[0].size()-1){
                return maxVal;
            }

            for(auto d : direc){
                int nextRow = row + d[0];
                int nextCol = col + d[1];

                if(nextRow < grid.size() && nextCol < grid[0].size() && nextRow >= 0 && nextCol >= 0 &&
                    visited[nextRow][nextCol] == 0){
                        pq.push({grid[nextRow][nextCol], nextRow, nextCol});
                    }
            }
        }

        return maxVal;
    }
};
