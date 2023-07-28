class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int solveEnv(vector<vector<int>>& envelopes){
        vector<int> ans;
        int n = envelopes.size();

        if(n == 0){
            return 0;
        }

        ans.push_back(envelopes[0][1]);
        for(int i = 1; i < n; i++){
            if(envelopes[i][1] > ans.back()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }

        return ans.size();
    }


    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);

        return solveEnv(envelopes);
    }
};
