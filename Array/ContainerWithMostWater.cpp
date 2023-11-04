class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maximumArea = 0;

        while(left < right)
        {
            int area=0;
            if(height[left] <= height[right])
            {
                area = height[left]*(right-left);
                left++;
            }
            else{
                area = height[right]*(right-left);
                right--;
            }
            maximumArea = max(area, maximumArea);
        }
        return maximumArea;
    }
};
