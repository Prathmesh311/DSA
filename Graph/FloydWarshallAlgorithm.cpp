#include<iostream>
#include<vector>
using namespace std;

#define INF 10000


vector<vector<int>> FloydWarshall(vector<vector<int>> graph){

    vector<vector<int>> dist(graph);
    int V = graph.size();

    //include k as intermediate vertex
    for(int k=0; k < V; k++){
        //Iterate over entire 2D array
        for(int i=0; i < V; i++){
            for(int j=0; j < V; j++){

                //if vertex k is included can we minimize the distance
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}


int main(){
    
    
    vector<vector<int>> graph = {{0, INF, -2, INF},
                                {4, 0, 3, INF},
                                {INF, INF, 0, 2},
                                {INF, -1, INF, 0}};
    
    vector<vector<int>> result = FloydWarshall(graph);

    for(int i=0; i < graph.size(); i++){
        for(int j=0; j < graph.size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
    
