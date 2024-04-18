class Solution {
public:
    int eatingValid(vector<int>& piles, int mid, int h){
        int numHours = 0;

        for(int i=0; i < piles.size(); i++){
            numHours += (piles[i] / mid) + (piles[i]%mid > 0 ? 1 : 0);
            
            if(numHours > h){
                return 1;
            }
        }

        return -1;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = 0;

        for(int i=0; i < piles.size(); i++){
            end = max(end, piles[i]);
        }

        int minEatingSpeed = end;

        while(start <= end){
            int mid = start + (end - start) / 2;

            int amount = eatingValid(piles, mid, h);
           
            if(amount == -1){
                end = mid-1;
                minEatingSpeed = min(minEatingSpeed, mid);
            }
            else if(amount == 1){
                start = mid+1;
            }

        }

        return minEatingSpeed;
    }
};
