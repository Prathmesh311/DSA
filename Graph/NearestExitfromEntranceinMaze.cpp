class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        queue<vector<int>> q;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int enterRow = entrance[0];
        int enterCol = entrance[1];

        q.push({enterRow, enterCol, 0});
        maze[enterRow][enterCol] = '+';

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i < size; i++){
                vector<int> v = q.front();
                q.pop();

                int currRow = v[0];
                int currCol = v[1];
                int distance = v[2];

                for(auto direc : directions){
                    int nextRow = currRow + direc[0];
                    int nextCol = currCol + direc[1];


                    if(nextRow >= rows || nextCol >= cols || nextRow < 0 || nextCol < 0){
                        if(currRow == enterRow && currCol == enterCol){
                            continue;
                        }
                        return distance;
                    }else if(maze[nextRow][nextCol] == '.'){
                        q.push({nextRow, nextCol, distance+1});
                        maze[nextRow][nextCol] = '+';
                    }
                }
            }
        }

        return -1;
        
    }
};
