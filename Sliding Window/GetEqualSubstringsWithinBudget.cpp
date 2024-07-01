class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++){
            maxCost -= abs((s[right] - 'a') - (t[right] - 'a'));

            if(maxCost < 0){
                maxCost += abs((s[left] - 'a') - (t[left] - 'a'));
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
