class Solution {
public:
    void traversePaths(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& currPath, int node, int n){
        if(node == n){
            paths.push_back(currPath);
            return;
        }

        for(int nextNode: graph[node]){
            currPath.push_back(nextNode);
            traversePaths(graph, paths, currPath, nextNode, n);
            currPath.pop_back();
        }
        
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> currPath;

        currPath.push_back(0);
        traversePaths(graph, paths,currPath, 0, graph.size()-1);

        return paths;
    }
};
