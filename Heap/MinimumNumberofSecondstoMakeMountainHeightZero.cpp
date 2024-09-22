class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pair<long long, pair<int, int>>, 
                            vector<pair<long long,pair<int ,int>>>,
                            greater<pair<long long,pair<int ,int>>>> pq;
        long long secondsReq = 0;

        for(int worker : workerTimes){
            pq.push({worker ,{worker, 1}});
        }

        while(mountainHeight > 0){
            auto p = pq.top();
            long long currTime = p.first;
            int originalNum = p.second.first;
            int iteration = p.second.second;
            pq.pop();

            pq.push({currTime + ((long long)originalNum * (iteration+1)), {originalNum, iteration+1}});

            secondsReq = max(secondsReq, currTime);
            mountainHeight--;
        }

        return secondsReq;
    }
};
