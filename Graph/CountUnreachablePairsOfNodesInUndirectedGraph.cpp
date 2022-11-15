class Solution {
public:

    int findSet(int i, int *parent){
        if(parent[i] == -1){
            return i;
        }

        //Path compression optimization
        return parent[i] = findSet(parent[i], parent);
    }

    void unionSet(int i, int j, int *parent, int *rank){
        int s1 = findSet(i, parent);
        int s2 = findSet(j, parent);

        //union by rank optimization
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

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        int *parent = new int[100001];
        int *rank = new int [100001];

        for(int i=0; i < 100001; i++){
            parent[i] = -1;
            rank[i] = 1;
        }


        for(auto p : edges){
            int s1 = findSet(p[0], parent);
            int s2 = findSet(p[1], parent);
            if(s1 != s2){
                unionSet(s1, s2, parent, rank);
            }
        }

        //calculating unrachable nodes
        long long ans = 0;
        for(int i=0; i < n; i++){
            ans += n - rank[findSet(i, parent)];
        }

        return ans/2;

    }
};
