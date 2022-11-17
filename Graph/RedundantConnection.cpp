class Solution {
public:

    int findSet(int i, int *parent){
        if(parent[i] == -1){
            return i;
        }
        
        //Path compression Optimization
        return parent[i] = findSet(parent[i], parent);
    }


    void unionSet(int i, int j, int *parent,int *rank){
        int s1 = findSet(i, parent);
        int s2 = findSet(j, parent);

        //Union by Rank Optimization
        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int *parent = new int[1001];
        int *rank = new int[1001];

        for(int i=1; i <= edges.size(); i++){
            parent[i] = -1;
            rank[i] = 1;
        }

        vector<int> v;
        for(auto egde : edges){
            int s1 = findSet(egde[0], parent);
            int s2 = findSet(egde[1], parent);

            if(s1 != s2){
                unionSet(s1, s2, parent, rank);
            }else{
                v.push_back(egde[0]);
                v.push_back(egde[1]);
                break;
            }
        }
        return v;
    }
};
