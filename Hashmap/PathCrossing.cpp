class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int, int>, bool> visited;

        int x = 0;
        int y = 0;

        visited[{x, y}] = true;

        for(int i=0; i < path.size(); i++){
            int direction = path[i];

            if(direction == 'N'){
                y++;
            }else if(direction == 'S'){
                y--;
            }else if(direction == 'E'){
                x++;
            }else if(direction == 'W'){
                x--;
            }

            if(visited.find({x, y}) != visited.end()){
                return true;
            }

            visited[{x, y}] = true;
        }

        return false;
    }
};
