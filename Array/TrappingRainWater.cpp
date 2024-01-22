class Solution {
public:

    //Method 1: with storing leftMax & rightMax
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);
        
        for(int i=1; i < height.size(); i++){
            leftMax[i] = max(height[i-1], leftMax[i-1]);
        }
        
        for(int i=height.size()-2; i >= 0; i--){
            rightMax[i] = max(height[i+1], rightMax[i+1]);
        }

        int trappedWater = 0;

        for(int i = 1; i < height.size()-1; i++){
            int maxHeight = min(rightMax[i], leftMax[i]);
            trappedWater += max(0, maxHeight - height[i]);
        }

        return trappedWater;
    }

    //Method 2: without storing leftMax & rightMax
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0; // No trapped water if there are less than 3 bars.
        }

        int leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        int trappedWater = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                trappedWater += max(0, leftMax - height[left]);
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                trappedWater += max(0, rightMax - height[right]);
                right--;
            }
        }

        return trappedWater;
    }

};
