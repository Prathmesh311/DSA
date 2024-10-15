class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<vector<int>> visited(rooms.size(), vector<int>(rooms[0].size(), 0));
        queue<vector<int>> q;
        vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        for(int i=0; i < rooms.size(); i++){
            for(int j=0; j < rooms[0].size(); j++){
                if(rooms[i][j] == 0){
                    q.push({i, j, 0});
                }
            }
        }

        while(!q.empty()){
            vector<int> v = q.front();
            q.pop();

            int row = v[0];
            int col = v[1];
            int distance = v[2];

            if(rooms[row][col] < distance || visited[row][col] == 1){
                continue;
            }

            rooms[row][col] = min(rooms[row][col], distance);
            visited[row][col] = 1;

            for(auto direction : directions){
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                if(nextRow >= 0 && nextCol >= 0 && nextRow < rooms.size() && nextCol < rooms[0].size()){
                    q.push({nextRow, nextCol, distance+1});
                }
            }
        }
    }
};
