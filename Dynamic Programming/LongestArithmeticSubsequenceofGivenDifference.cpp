class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> map;

        int ans = 1;
        for(int i=0; i < arr.size(); i++){
            int num = arr[i];
            if(map.find(num-difference) != map.end()){
                map[num] = map[num - difference] + 1;
            }
            else{
                map[num] = 1;
            }

            ans = max(ans, map[num]);
        }

        return ans;
    }
};
