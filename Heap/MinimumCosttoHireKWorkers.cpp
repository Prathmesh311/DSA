class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers;

        for(int i=0; i < quality.size(); i++){
            workers.push_back({(double)wage[i]/quality[i], quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> pq;
        double minCost = numeric_limits<double>::max();
        int totalQuality = 0;

        for(auto p : workers){
            totalQuality += p.second;
            pq.push(p.second);

            if(pq.size() > k){
                totalQuality -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                minCost = min(minCost, totalQuality * p.first);
            }
        }

        return minCost;
    }
};
