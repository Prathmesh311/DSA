class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        vector<int> nums;

        // Fill nums with values from 1 to n
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        // Factorial to store the factorial of each number from 0 to n-1
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        // Decrement k to convert to 0-based index
        --k;

        for (int i = n - 1; i >= 0; --i) {
            int index = k / factorial[i];
            k %= factorial[i];

            result += to_string(nums[index]);

            // Erase the selected number from the vector
            nums.erase(nums.begin() + index);
        }

        return result;
    }
};
