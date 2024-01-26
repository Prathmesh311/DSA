#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;

        for(int i = 0; i < startTime.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> dp(jobs.size(), 0);

        dp[0] = jobs[0][2];

        for(int i = 1; i < jobs.size(); i++) {
            int prevJob = upper_bound(jobs.begin(), jobs.begin() + i, jobs[i][0], 
                                      [](int val, const vector<int>& job) {
                                          return val < job[1];
                                      }) - jobs.begin() - 1;

            dp[i] = max(dp[i-1], (prevJob != -1 ? dp[prevJob] : 0) + jobs[i][2]);
        }

        return dp[jobs.size() - 1];
    }
};


