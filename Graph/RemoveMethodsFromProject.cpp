class Solution {
public:
    // Function to mark all suspicious methods using BFS (from method k)
    void bfsInfect(int n, int node, unordered_map<int, set<int>> &adj, vector<int> &infected) {
        queue<int> q;
        q.push(node);
        
        while(!q.empty()) {
            int currNode = q.front();
            q.pop();
            
            infected[currNode] = 1;  // Mark as suspicious
            
            for(int nextNode : adj[currNode]) {
                if (!infected[nextNode]) {  // Only push if not already marked suspicious
                    q.push(nextNode);
                }
            }
        }
    }
    
    // Function to check if suspicious methods can be removed
    bool canRemoveAllSuspicious(int n, vector<int>& infected, unordered_map<int, set<int>>& reverseAdj) {
        for (int i = 0; i < n; i++) {
            if (infected[i] == 1) {  // If this method is suspicious
                // Check if any non-suspicious method invokes it
                for (int invoker : reverseAdj[i]) {
                    if (infected[invoker] == 0) {
                        // Non-suspicious method invokes a suspicious one, cannot remove
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> infected(n, 0);  // Track which methods are suspicious
        unordered_map<int, set<int>> adj, reverseAdj;  // Adjacency and reverse adjacency
        
        // Build the adjacency and reverse adjacency lists
        for (auto p : invocations) {
            adj[p[0]].insert(p[1]);       // p[0] invokes p[1]
            reverseAdj[p[1]].insert(p[0]); // Reverse: p[1] is invoked by p[0]
        }
        
        // Perform BFS to mark all methods directly or indirectly invoked by k as suspicious
        bfsInfect(n, k, adj, infected);
        
        // Check if suspicious methods can be removed
        if (canRemoveAllSuspicious(n, infected, reverseAdj)) {
            // Add all non-suspicious methods to the result
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                if (infected[i] != 1) {
                    ans.push_back(i);
                }
            }
            return ans;
        } else {
            // If we cannot remove suspicious methods, return all methods
            vector<int> allMethods;
            for (int i = 0; i < n; i++) {
                allMethods.push_back(i);
            }
            return allMethods;
        }
    }
};
