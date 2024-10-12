class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> edges(10000001, 0);

        for(auto v : intervals){
            if(v[0] == v[1]){
                edges[v[0]] += 1;
            }else{
                edges[v[0]] += 1;
                edges[v[1]+1] -= 1;
            }
        }

        int currIntersect = 0;
        int maxIntersect = INT_MIN;
        for(int i=0; i < edges.size(); i++){
            currIntersect += edges[i];
            maxIntersect = max(maxIntersect, currIntersect);
        }

        return maxIntersect;
    }
};
