class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> res(isWater.size(), vector<int>(isWater[0].size(), -1));
        vector<vector<int>> direc = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        queue<pair<int, int>> q;

        for(int i=0; i < isWater.size(); i++){
            for(int j=0; j < isWater[0].size(); j++){
                if(isWater[i][j] == 1){
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();

            for(auto d : direc){
                int nextRow = p.first + d[0];
                int nextCol = p.second + d[1];

                if(nextRow >= 0 && nextCol >= 0 && nextCol < isWater[0].size() 
                    && nextRow < isWater.size() && res[nextRow][nextCol] == -1){
                        q.push({nextRow, nextCol});
                        res[nextRow][nextCol] = res[p.first][p.second] + 1;
                }
            }
        }

        return res;
    }
};
