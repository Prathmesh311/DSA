class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> map;
        set<int> set;

        for(int num : arr){
            map[num] += 1;
        }

        for(auto p : map){
            int occurances = p.second;

            if(set.find(occurances) != set.end()){
                return false;
            }
            set.insert(occurances);
        }

        return true;
    }
};
