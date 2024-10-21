class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<pair<int, int>>> adj;
        queue<pair<int, int>> q;


        for(int i=0; i < manager.size(); i++){
            if(manager[i] == -1){
                continue;
            }
            adj[manager[i]].push_back({i, informTime[manager[i]]});
        }

        q.push({headID, 0});
        int maxTimeRequired = 0;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int currEmp = p.first;
            int currTime = p.second;

            maxTimeRequired = max(maxTimeRequired, currTime);


            for(auto next : adj[currEmp]){
                int nextEmp = next.first;
                int nextTime = next.second + currTime;

                q.push({nextEmp, nextTime});
            }
        }

        return maxTimeRequired;

    }
};
