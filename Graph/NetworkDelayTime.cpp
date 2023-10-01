class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<vector<int>>> adj;

        for(auto time: times){             //Created adj list with nebouring ele and cost
            int src = time[0];
            int des = time[1];
            int wei = time[2];
            
            vector<int> temp{des, wei};
            adj[src].push_back(temp);
        }

        vector<int> distance(101, INT_MAX);
        priority_queue<pair<int, int>> pq;
        int maxDelay = 0;

        pq.push({k, 0});                     //Pushed starting node to pq
        distance[k] = 0;

        while(!pq.empty()){
            pair p = pq.top();
            pq.pop();

            int node = p.first;
            
            for(auto adjEle: adj[node]){    
                int nbr = adjEle[0];
                int cost = adjEle[1];

                if(distance[nbr] > distance[node] + cost){   //Updating the distance
                    distance[nbr] = distance[node] + cost;
                    pq.push({nbr, distance[nbr]});
                }
            }
        }

        for(int i=1; i <= n; i++){                        //Checking if all ele are accessible or not
            if(distance[i] != INT_MAX){
                maxDelay = max(maxDelay, distance[i]);    //Checking max delay to reach all nodes
            }
            else{
                return -1;
            }
        }
        if(maxDelay == 0){
            return -1;
        }

        return maxDelay;
    }
};
