class Solution {
public:
    bool isFeasible(vector<int>& bloomDay, int m, int k, int days){
        int continueDays = 0;

        for(int i=0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= days){
                continueDays++;

                if(continueDays == k){
                    continueDays = 0;
                    m--;
                }
            }else{
                continueDays = 0;
            }
        }

        if(m > 0){
            return false;
        }
        return true;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        if (long(bloomDay.size()) < long(m) * long(k)) {
            return -1;
        }

        while(left < right){
            int mid = left + (right-left)/2;

            if(isFeasible(bloomDay, m, k, mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};
