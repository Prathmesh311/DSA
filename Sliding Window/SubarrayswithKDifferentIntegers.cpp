class Solution {
public:
     int atMost(vector<int> &nums, int k){
        unordered_map<int, int> map;
       
        int subArrays = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            map[nums[right]] += 1;  

            while(left <= right && map.size() > k){
                map[nums[left]] -= 1; 

                if(map[nums[left]] == 0){
                    map.erase(nums[left]);
                }
                left++;
            }

            subArrays += right - left + 1;
        }

        return subArrays;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
