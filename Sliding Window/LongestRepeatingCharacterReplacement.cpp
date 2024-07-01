class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        
        int maxLen = 0;
        int left = 0;
        int maxCount = 0;

        for(int right = 0; right < s.size(); right++){
            map[s[right]] += 1;
            maxCount = max(maxCount, map[s[right]]);

            if(right - left + 1 - maxCount > k){
                map[s[left]] -= 1;  
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
