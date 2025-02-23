class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long maxSum = 0;
        
        priority_queue<int> pq;
        
        for(int i=0; i < grid.size(); i++){
            sort(grid[i].begin(), grid[i].end(), greater<int>());
            int index = 0;
            while(limits[i] > 0){
                pq.push(grid[i][index]);
                limits[i] -= 1;
                index++;
            }
        }
        
        while(k > 0){
            maxSum += (long long)pq.top();
            pq.pop();
            
            k--;
        }
        
        return maxSum;
    }
};
