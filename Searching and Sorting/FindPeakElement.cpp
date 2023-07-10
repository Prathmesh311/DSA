class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;


        while(start <= end){
            int mid = (start+end)/2;

            int currNum = nums[mid];


            if((mid-1 < 0  || currNum > nums[mid-1]) && (mid+1 > nums.size()-1  || currNum > nums[mid+1])){
                return mid;
            }

            if(mid-1 >= 0  && currNum < nums[mid-1]){
                end = mid-1;
            }
            else if(mid+1 < nums.size() && currNum < nums[mid+1]){
                start = mid+1;
            }
        }

        return -1;
    }
};
