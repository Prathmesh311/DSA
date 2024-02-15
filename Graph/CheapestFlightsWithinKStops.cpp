class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Method 1 : Dijktra's algo :- TLE
        //dijktras(n, flights, src, dst, k);

        //Method 2: Bellmon Ford
        return bellmonFord(n, flights, src, dst, k);

        //Method 3 : BFS + Dijktra's (100% faster)
        //dijktrasBFS(n, flights, src, dst, k);
    }

    int bellmonFord(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n, INT_MAX);
        price[src] = 0;

        for(int i = 0; i <= k; i++){
            vector<int> temp = price;

            for(auto v : flights){
                if(price[v[0]] == INT_MAX){
                    continue;
                }

                if(temp[v[1]] > price[v[0]] + v[2]){
                    temp[v[1]] = price[v[0]] + v[2];
                }
            }
            price = temp;
        }

        return price[dst] == INT_MAX ? -1 : price[dst];
    }

    //Dijktra's algo :- giving TLE
    int dijktras(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto v : flights){
            adj[v[0]].push_back({v[1], v[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            
            int currCost = v[0];
            int currNode = v[1];
            int currStops = v[2];
            
            if(currNode == dst){
                return currCost;
            }

            if(currStops <= k){
                for(auto next : adj[currNode]){
                    pq.push({currCost + next.second, next.first, currStops+1});
                }
            }
        }

        return -1;
    }
    
    int dijktrasBFS(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];

            adj[u].push_back({v, cost});
        }

        vector<int> distance(n, 1e9);
        distance[src] = 0;

        //{stops,{node,cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();

            if (stops > K){
                continue;
            }
            for (auto it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;

                if (wt + dis < distance[adjnode] and stops <= K){
                    q.push({stops + 1, {adjnode, wt + dis}});
                    distance[adjnode] = wt + dis;
                }
            }
        }

        if (distance[dst] == 1e9){
            return -1;
        }
        return distance[dst];
    }

};
