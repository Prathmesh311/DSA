class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // Step 1: Map each number to its position in the sorted array for group assignment
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        unordered_map<int, int> groupMap; // Maps each number to its group
        vector<queue<int>> groups;       // Queues to store numbers in each group
        int currentGroup = 0;

        // Step 2: Divide sorted numbers into groups based on the limit
        for (int i = 0; i < sortedNums.size(); i++) {
            if (i > 0 && abs(sortedNums[i] - sortedNums[i - 1]) > limit) {
                currentGroup++; // Start a new group if the limit is exceeded
            }

            // Assign the current number to the group
            if (groups.size() <= currentGroup) {
                groups.push_back(queue<int>()); // Create a new group if needed
            }
            groups[currentGroup].push(sortedNums[i]);
            groupMap[sortedNums[i]] = currentGroup;
        }

        // Step 3: Construct the result array
        vector<int> result;
        for (int num : nums) {
            int groupNum = groupMap[num];          // Find the group of the current number
            result.push_back(groups[groupNum].front()); // Add the smallest number in the group
            groups[groupNum].pop();               // Remove the number from the group
        }

        return result;
    }
};
