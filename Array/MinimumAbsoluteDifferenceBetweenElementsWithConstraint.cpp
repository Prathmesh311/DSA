class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int minDiff = INT_MAX;
        set<int> set;

        for(int i=x; i < nums.size(); i++){
            set.insert(nums[i-x]);

            auto it = set.upper_bound(nums[i]);              //find element close to element in set

            if(it != set.end()){                             //find diff between uppper bound and element
                minDiff = min(minDiff, abs(nums[i] - *it));
            }
 
            if(it != set.begin()){                           //find diff between prev upperbound and element
                minDiff = min(minDiff, abs(nums[i] - *prev(it)));
            }
        }
        
        return minDiff;
    }
};
