class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;

        int maxLen = 0;
        int left = 0;

        for(int right = 0; right < s.size(); right++){
            if(map[s[right]] == 0 || map.find(s[right]) == map.end()){
                map[s[right]] = 1;
                maxLen = max(maxLen, right - left + 1);
            }else{
                while(left < right){
                    if(s[left] == s[right]){
                        left++;
                        break;
                    }
                    map[s[left]] -= 1;
                    left++;
                }
            }
        }

        return maxLen;
    }
};
