class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> jobOptions;

        for(int i=0; i < difficulty.size(); i++){
            jobOptions.push_back({difficulty[i], profit[i]});
        }

        sort(jobOptions.begin(), jobOptions.end());

        int currMaxProfit = 0;
        for(int i=0; i < jobOptions.size(); i++){
            currMaxProfit = max(currMaxProfit, jobOptions[i][1]);
            jobOptions[i][1] = currMaxProfit;
        }


        int maxProfit = 0;

        for(int i=0; i < worker.size(); i++){
            int workerCapacity = worker[i];

            int left = 0;
            int right = jobOptions.size()-1;

            int workerProfit = 0;

            while(left < right){
                int mid = left + (right - left)/2;

                if(jobOptions[mid][0] > workerCapacity){
                    right = mid;
                }else{
                    left = mid+1;
                }
            }

            if(left == 0){
                if(jobOptions[left][0] > workerCapacity){
                    continue;
                }
            }else{
                if(jobOptions[left][0] > workerCapacity){
                    maxProfit += jobOptions[left-1][1];
                }else{
                    maxProfit += jobOptions[left][1];
                }
            }
        }

        return maxProfit;
    }
};
