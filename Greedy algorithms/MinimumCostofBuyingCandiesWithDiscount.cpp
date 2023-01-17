class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<>());

        int totalCost = 0;
        int counter = 0;
        for(int i=0; i < cost.size(); i++){
            if(counter == 2){               //Take 2 candies and skip every 3rd candy
                counter = 0;
                continue;
            }

            totalCost += cost[i];
            counter++;
        }
        
        return totalCost;
    }
};
