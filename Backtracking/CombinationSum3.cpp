class Solution {
public:

    void combinations(vector<vector<int>> &ans, vector<int> comb, int sum, int k, int n, int index){
        if(k < 0){
            return;
        }

        if(k == 0){
            if(sum == n){
                ans.push_back(comb);
            }
            else{
                return;
            }
        }

        for(int i=index; i <= 9; i++){
            comb.push_back(i);
            combinations(ans, comb, sum + i, k - 1, n, i+1);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        int sum = 0;

        combinations(ans, comb, sum, k, n, 1);
        return ans;
    }
};
