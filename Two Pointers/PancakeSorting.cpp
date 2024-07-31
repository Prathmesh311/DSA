class Solution {
public:
    vector<int> pancakeSort(std::vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();

        for (int curr_size = n; curr_size > 1; --curr_size) {
            int max_index = max_element(arr.begin(), arr.begin() + curr_size) - arr.begin();

            if (max_index != curr_size - 1) {
                if (max_index > 0) {
                    ans.push_back(max_index + 1);
                    reverse(arr.begin(), arr.begin() + max_index + 1);
                }

                ans.push_back(curr_size);
                reverse(arr.begin(), arr.begin() + curr_size);
            }
        }

        return ans;
    }
};
