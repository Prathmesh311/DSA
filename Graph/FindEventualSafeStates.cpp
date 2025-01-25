class Solution {
public:
    bool isSafe(vector<vector<int>>& graph, unordered_map<int, bool> &safe, int node){
        if(safe.find(node) != safe.end()){
            return safe[node];
        }
        
        safe[node] = false;
        for(auto nextNode : graph[node]){
            if(!isSafe(graph, safe, nextNode)){
                return safe[node];
            }
        }

        safe[node] = true;
        return safe[node];
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> safe;
        vector<int> result;

        for(int i=0; i < graph.size(); i++){
            if(isSafe(graph, safe, i)){
                result.push_back(i);
            }
        }

        return result;
    }
};
