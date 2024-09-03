class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size());
        map<int, int> map;

        for(int i=0; i < intervals.size(); i++){
            map[intervals[i][0]] = i; 
        }

        for(int i=0; i < intervals.size(); i++){
            auto it = map.lower_bound(intervals[i][1]);

            if(it != map.end()){
                ans[i] = it->second;        
            }else{
                ans[i] = -1;
            }
        }

        return ans;
    }
};