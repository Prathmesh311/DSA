class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxLeft;
        vector<int> maxRight;
        
        int maxLeftTillNow = 0;
        for(int i=0; i < height.size(); i++){
            maxLeftTillNow = max(maxLeftTillNow, height[i]);
            maxLeft.push_back(maxLeftTillNow);
        }

        int maxRightTillNow = 0;
        for(int i=height.size()-1; i >= 0; i--){
            maxRightTillNow = max(maxRightTillNow, height[i]);
            maxRight.insert(maxRight.begin() ,maxRightTillNow);
        }

        int trappedWater = 0;
        for(int i=0; i < height.size(); i++){
            if(maxLeft[i] > height[i] && height[i] < maxRight[i]){
                int rainAmount = min(maxLeft[i], maxRight[i]) - height[i];
                trappedWater += rainAmount; 
            }
        }

        return trappedWater;
    }
};
