class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int price : prices){
            pq.push(price);
        }

        int amount1 = pq.top();
        pq.pop();
        int amount2 = pq.top();

        int remaining = money - (amount1 + amount2);

        if(remaining < 0){
            return money;
        }


        return remaining;
    }
};
