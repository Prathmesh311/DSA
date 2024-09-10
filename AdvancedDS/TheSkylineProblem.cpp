class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;

        map<int, vector<int>> map;
        multiset<int> heights;
       
        for(auto building : buildings){
            map[building[0]].push_back(-building[2]);
            map[building[1]].push_back(building[2]);
        }


        int prevNum = 0;
        int maxElement;
        for(auto p : map){
            sort(p.second.begin(), p.second.end());
            
            for(auto v : p.second){
                if(v < 0){
                    heights.insert(abs(v));
                    
                }else{
                    heights.erase(heights.find(abs(v)));
                
                }

                maxElement = heights.empty() ? 0 : *heights.rbegin();
                if(maxElement != prevNum){
                    ans.push_back({p.first, maxElement});
                    prevNum = maxElement;
                }
            }
        }

        return ans;
    }
};
