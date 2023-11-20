class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        unordered_map<char, int> map;

        int maxF = 0;

        for(int i=0; i < s.size(); i++){
            maxF = max(maxF, ++map[s[i]]);

            if(ans - maxF < k){
                ans++;
            }
            else{
                map[s[i - ans]]--;
            }
        }
        return ans;
    }
};
