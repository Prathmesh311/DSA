class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         priority_queue<int,vector<int>,greater<int>> Q;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                Q.push(matrix[i][j]);
            }
        }

        while(--k){ 
            Q.pop();
        }
        return Q.top();
    }
};
