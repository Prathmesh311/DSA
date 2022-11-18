#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class DSU{
        int *parent;
        int *rank;
        
    public:
        DSU(int V){
            parent = new int[V];
            rank = new int[V];

            for(int i=0; i < V; i++){
                parent[i] = -1;
                rank[i] = 1;
            }

        }

        int findSet(int i){
            if(parent[i] == -1){
                return i;
            }

            return parent[i] = findSet(parent[i]);
        }

        void unionSet(int i, int j){
            int s1 = findSet(i);
            int s2 = findSet(j);

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
};

class Graph{

    int V;
    

    public: 
        vector<vector<int>> edges;
        Graph(int V){
            this->V = V;
        }
        void addEdge(int x, int y, int w){
            edges.push_back({w, x, y});
        }

        int krushkalMST(){
            DSU s(V);

            //Sorting edges according to weights
            sort(edges.begin(),edges.end());


            int totalCost = 0;
            for(auto edge : edges){
                
                int w = edge[0];
                int x = edge[1];
                int y = edge[2];

                if(s.findSet(x) != s.findSet(y)){
                    s.unionSet(x, y);
                    totalCost += w;
                } 
            }

            return totalCost;
        }

};

int main(){
    Graph g(4);

    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);

    cout<<g.krushkalMST();

    return 0;
}