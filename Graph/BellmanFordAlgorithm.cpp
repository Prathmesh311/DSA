#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int src, int V, vector<vector<int>> edges){
        vector<int> dist(V+1, INT16_MAX);
        dist[src] = 0; 

        for(int i=0; i <= V-1; i++){
            for(auto edge : edges){
                int n = edge[0];
                int m = edge[1];
                int w = edge[2];

                if(dist[n]!= INT16_MAX && dist[n] + w < dist[m]){
                    dist[m] = dist[n] + w;
                }
            }
        }

        //Checking if negative cycle is presnet or not
        for(auto edge : edges){
                int n = edge[0];
                int m = edge[1];
                int w = edge[2];

                if(dist[n]!= INT16_MAX && dist[n] + w < dist[m]){
                    cout<<"Negative cycle present!";
                    exit(0);
                }
        }

        return dist;
    }





int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> edges;

    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u, v, w});
    }


    vector<int> distance = bellmanFord(1, m, edges);

    for(int i = 1; i < distance.size(); i++){
        cout<<i<<" -> "<<distance[i]<<endl;
    }

    return 0;
}