class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        sort(tickets.begin(), tickets.end());
        
        for (int i = 0; i < tickets.size(); i++) {
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        vector<string> result;

        dfs(adj, "JFK", result);

        reverse(result.begin(), result.end());
        return result;
    }
private:
    void dfs(unordered_map<string, vector<string>>& adj, string from, vector<string>& result) {
        
        while (!adj[from].empty()) {
            string to = *adj[from].begin();
            adj[from].erase(adj[from].begin());

            dfs(adj, to, result);
        }
        
        result.push_back(from);
    }
};
