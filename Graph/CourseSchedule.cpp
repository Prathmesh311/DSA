class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        bool *visited = new bool[numCourses];
        int *inDegree = new int[numCourses];
        queue<int> q;
        

        for(int i=0; i < numCourses; i++){
            inDegree[i] = 0;
        }

        for(auto p : prerequisites){    //Created adjList, degree of dependancy on other nodes
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
            visited[p[0]] = false;
            visited[p[1]] = false;
        }

        for(int i=0; i < numCourses; i++){   //push nodes free from dependancy to queue
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){                   //BFS
            int node = q.front(); 
            q.pop();
            visited[node] = true;
            
            for(int nbr : adj[node]){
                if(!visited[nbr]){
                    inDegree[nbr]--;        //reduce dependacy by 1
                    if(inDegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
        }

        for(int i=0; i< numCourses; i++){  
            if(!visited[i]){
                return false;
            }
        }

        return true;
    }
};
