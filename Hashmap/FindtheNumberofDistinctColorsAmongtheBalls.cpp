class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> posToColor;
        unordered_map<int, unordered_set<int>> colorToPos;
        vector<int> result;

        for(int i=0; i < queries.size(); i++){
            if(posToColor.find(queries[i][0]) != posToColor.end()){
                int currColor = posToColor[queries[i][0]];
                colorToPos[currColor].erase(queries[i][0]);

                if(colorToPos[currColor].size() <= 0){
                    colorToPos.erase(currColor);
                }
            }

            posToColor[queries[i][0]] = queries[i][1];
            colorToPos[queries[i][1]].insert(queries[i][0]);

            result.push_back(colorToPos.size());
        }

        return result;
    }
};
