class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);     //Find first intersection of 2 pointers
    
        slow = 0;
        while (slow != fast) {     //find starting point of loop/cycle
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
