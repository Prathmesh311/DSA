class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n+1, 0);

        for(int i=0; i < trust.size(); i++){
            count[trust[i][0]]--;
            count[trust[i][1]]++;
        }

        for(int i=1; i < count.size(); i++){
            if(count[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};
