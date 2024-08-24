class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int requiredRadius = 0;

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());


        for(int i=0; i < houses.size(); i++){
            int housePos = houses[i];

            int left = 0;
            int right = heaters.size()-1;

            while(left < right){
                int mid = left + (right-left)/2;

                if(housePos <= heaters[mid]){
                    right = mid;
                }else{
                    left = mid+1;
                }
            }

            int leftHeater = left > 0 ? abs(heaters[left-1] - housePos) : INT_MAX;
            int rightHeater = right < heaters.size() ? abs(heaters[right] - housePos) : INT_MAX;

            requiredRadius = max(requiredRadius, min(leftHeater, rightHeater));
        }

        return requiredRadius;
    }
};
