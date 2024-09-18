class Solution {
public:
    static bool comparator(const string &str1, const string &str2) {
        return str1 + str2 > str2 + str1;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Sort strings using the custom comparator
        sort(strNums.begin(), strNums.end(), comparator);

        // Edge case: if the highest number is "0", the result is "0"
        if (strNums[0] == "0") {
            return "0";
        }

        // Construct the largest number from the sorted strings
        string largestNum;
        for (const string &num : strNums) {
            largestNum += num;
        }

        return largestNum;
    }
};
