class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<int, vector<pair<int, int>>> adj;
        map<int, bool> visited;


        for(int i=0; i < points.size(); i++){
            visited[i] = false;
            for(int j=i+1; j < points.size(); j++){
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({cost, j});
                adj[j].push_back({cost, i});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        int minCost = 0;

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();

            int cost = p.first;
            int nextPoint = p.second;

            if(visited[nextPoint] == true){
                continue;
            }

            visited[nextPoint] = true;
            minCost += cost;

            for(auto possibleConn : adj[nextPoint]){
                if(visited[possibleConn.second] == false){
                    pq.push(possibleConn);
                }
            }
        }

        return minCost;
    }
};
