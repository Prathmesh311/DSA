class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;

        //method1: Greedy
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


        //Method2: 2-pointer - eleminating 1 balloon amount current 2 balloons
        int left = 0;

        for(int right = 1; right < colors.size(); right++){
            if(colors[left] == colors[right]){
                if(neededTime[left] < neededTime[right]){
                    cost += neededTime[left];
                    left = right;
                }else{
                    cost += neededTime[right];
                }
            }else{
                left = right;
            }
        }

        return cost;
    }
};
