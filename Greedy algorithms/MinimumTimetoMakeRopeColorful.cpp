class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;

        for(int i=1; i < colors.size(); i++){
            if(colors[i] == colors[i-1]){
                int j = i;

                int totalCost = neededTime[j-1];
                int currMax = neededTime[j-1];

                while(colors[j] == colors[j-1]){
                    totalCost += neededTime[j];
                    currMax = max(currMax, neededTime[j]);
                    j++;
                }
                
                cost += (totalCost - currMax);

                i = j-1;
            }
        }

        return cost;
    }
};
