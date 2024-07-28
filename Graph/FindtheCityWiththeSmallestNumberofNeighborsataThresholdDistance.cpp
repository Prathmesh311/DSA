class Solution {
public:
    // Method: Floyd-Marshall Algorithm
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>> dp(n, vector<int>(n, 10001));
        int minNeighborNode;
        int minNeighbors = INT_MAX;

        for(int i = 0; i < n; i++){
            dp[i][i] = 0;
        }

        for(auto edge : edges){
            dp[edge[0]][edge[1]] = edge[2];
            dp[edge[1]][edge[0]] = edge[2];
        }

        for(int k=0; k < n; k++){
            for(int row = 0; row < n; row++){
                for(int col = 0; col < n; col++){
                    dp[row][col] = min(dp[row][col], dp[row][k] + dp[k][col]);
                }
            }
        }

        for(int row = 0; row < n; row++){
            int canVisit = 0;
            for(int col = 0; col < n; col++){
                if(dp[row][col] <= distanceThreashold){
                    canVisit++;
                }
            }

            if(canVisit <= minNeighbors){
                minNeighborNode = row;
                minNeighbors = canVisit;
            }
        }
    
        return minNeighborNode;
    }
};
