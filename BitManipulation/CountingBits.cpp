class Solution {
public:
    int countSetBits(int n){
        int setBits = 0;

        while(n > 0){
            n = n & (n-1);
            setBits++;
        }
        return setBits;
    }

    vector<int> countBits(int n) {
        vector<int> ans;

        ans.push_back(0);

        for(int i=1; i <= n; i++){
            int currSetBits = countSetBits(i);
            ans.push_back(currSetBits);
        }

        return ans;
    }
};
