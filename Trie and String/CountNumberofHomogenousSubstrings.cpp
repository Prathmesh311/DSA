class Solution {
public:
    int countHomogenous(string s) {
        long long totalCount = 0;
        int mod = 1000000007;
        int homoLen = 1;

        for(int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                homoLen++;
                continue;
            } else {
                //number combinations are len of(continuos same chars) = homoLen
                totalCount += ((static_cast<long long>(homoLen) * (homoLen + 1)) % mod) / 2;
                homoLen = 1;
            }
        }
        
        if (homoLen > 0) {
            totalCount += ((static_cast<long long>(homoLen) * (homoLen + 1)) % mod) / 2;
        }
        
        return static_cast<int>(totalCount);
    }
};
