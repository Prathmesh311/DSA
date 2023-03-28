class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1){
            return 0;
        }
        int sellingPrices[prices.size()];
        int maxPrice = 0;

        for(int i = prices.size()-1; i > 0; i--){
            if(prices[i] > maxPrice){
                maxPrice = prices[i];
            }
            sellingPrices[i] = maxPrice;
        }

        int maximumPorfit = 0;
        for(int i=0; i <= prices.size()-2; i++){
            int profit = sellingPrices[i+1] - prices[i];
            if(profit > maximumPorfit){
                maximumPorfit = profit;
            }
        }

        return maximumPorfit;
        
    }
    
    //Simpler method
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;


        int minVal = prices[0];
        for(int i=1; i < prices.size(); i++){
            if(prices[i] > minVal){
                maximumProfit = max(maximumProfit, prices[i] - minVal);
            }
            else{
                minVal = min(minVal, prices[i]);
            }
        }
        
        return maximumProfit;
    }
};
