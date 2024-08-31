class Solution {
public:
    void traverse(vector<int> &nums, vector<int> &v, int index, int sum){
        if(index >= nums.size()){
            v.push_back(sum);
            return;
        }

        traverse(nums, v, index+1, (sum + nums[index]) % 1000000009);
        traverse(nums, v, index+1, sum);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> v1;
        vector<int> v2;

        vector<int> firstHalf(nums.begin(), nums.begin() + nums.size() / 2);
        vector<int> secondHalf(nums.begin() + nums.size() / 2, nums.end());

        traverse(firstHalf, v1, 0, 0);
        traverse(secondHalf, v2, 0, 0);

        sort(v2.begin(), v2.end());

        int minDiff = INT_MAX;

        for(int num : v1){
            int rem = goal - num;

            int left = 0;
            int right = v2.size();

            while(left < right){
                int mid = left + (right-left)/2;

                if(v2[mid] < rem){
                    left = mid+1;
                }else{
                    right = mid;
                }
            }

            if(left > 0){
                minDiff = min(minDiff, abs(v2[left-1] - rem));
            }
            if(left < v2.size()){
                minDiff = min(minDiff, abs(v2[left] - rem));
            }
        }

        return minDiff;
    }
};
