class StockSpanner {
    stack<int> stack;
    vector<int> prices;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {

      
        int stockSpan = 1;
        if(stack.size() == 0){             //when stack is empty directly push price and index and return 1
            prices.push_back(price);
            stack.push(prices.size()-1);
            return 1;
        }else{
            while(stack.size() > 0 && price >= prices[stack.top()]){     //pop indexes from stack until it founds larger price
                stack.pop();
            }

            if(stack.size() == 0){
                prices.push_back(price);
                stack.push(prices.size()-1);
                return prices.size();
            }

            prices.push_back(price);                     
            stockSpan = prices.size() - 1 - stack.top();  //find the stockSpan between 2 stock prices
            stack.push(prices.size()-1);
        }

        return stockSpan;
       
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
