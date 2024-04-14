class Solution {
public:
    bool feasible(vector<int>& weights, int days, int capacity){
        int total = 0;

        for(int weight : weights){
            total += weight;
            if(total > capacity){
                total = weight;
                days--;
                if(days <= 0){
                    return false;
                }
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while(left < right){
            int mid = left + (right - left) / 2;

            if(feasible(weights, days, mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};
