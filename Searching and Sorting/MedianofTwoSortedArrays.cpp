class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {        
        int size1 = nums1.size(), size2 = nums2.size();
        int total = size1 + size2, half = total / 2;
        
        if(size1 > size2)
            return findMedianSortedArrays(nums2, nums1);
        
        int start = 0, end = size1 - 1;
        while(true)
        {
            int mid = floor((start + end) / 2.0); // (start + end) // 2
            int left1 = mid, left2 = half - mid - 2; // 0 based indexing
            
            int curr1 = left1 >= 0 ? nums1.at(left1) : INT32_MIN;
            int curr2 = left2 >= 0 ? nums2.at(left2) : INT32_MIN;
            int next1 = left1 + 1 < size1 ? nums1.at(left1 + 1) : INT32_MAX;
            int next2 = left2 + 1 < size2 ? nums2.at(left2 + 1) : INT32_MAX;
            
            if(curr1 <= next2 and curr2 <= next1)
            {
                if(total & 1)
                   return min(next1, next2);
                else
                    return (max(curr1, curr2) + min(next1, next2)) / 2.0;
            }
            else if(curr1 > next2)
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
};
