class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit= 0;

        int buyPrice = prices[0];
        for(int i=1; i < prices.size(); i++){
            if(buyPrice < prices[i]){
                totalProfit += prices[i] - buyPrice;
                buyPrice = prices[i];
            }
            else{
                buyPrice = prices[i];
            }
        }

        return totalProfit;
    }
};
