class Solution {
public:
     bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int partitioning(string &s, vector<int> &dp, int index){
        if(index >= s.size()){
            return 0;
        }

        if(dp[index] != INT_MAX){
            return dp[index];
        }

    
        int currCuts = INT_MAX;
        for(int pos = index; pos < s.size(); pos++){
            
            if(isPalindrome(s, index, pos)){
                int cuts = partitioning(s, dp, pos+1) + 1;
                currCuts = min(currCuts, cuts);
            }
        }
        dp[index] = currCuts;

        return dp[index];
    }

    int minCut(string s) {
        vector<int> dp(s.size(), INT_MAX);
        int totalCuts =  partitioning(s, dp, 0);

        return totalCuts-1;
    }
};
