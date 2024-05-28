class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxSubStr = 0;

        int left = 0;
        int right = 0;

        while(right < s.size()){
            int diff = abs((s[right] - 'a') - (t[right]-'a'));

            if(maxCost >= diff){ 
                maxCost -= diff;
                right++;
                maxSubStr = max(maxSubStr, right-left);
            }else{
                maxCost += abs((s[left] - 'a') - (t[left]-'a'));
                left++;
            }
        }

        return maxSubStr;
    }
};
