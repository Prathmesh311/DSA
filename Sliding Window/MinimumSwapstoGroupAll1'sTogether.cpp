class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;

        for(int num : data) {
            if(num == 1) {
                ones++;
            }
        }

        if (ones == 0 || ones == 1) {
            return 0;
        }

        int maxOnesInWindow = 0;
        int left = 0;

        int maxOnes = 0;

        for (int right = 0; right < data.size(); right++) {
            if (data[right] == 1) {
                maxOnesInWindow++;
            }

            if (right - left + 1 > ones) {
                if (data[left] == 1) {
                    maxOnesInWindow--;
                }
                left++;
            }
            maxOnes = max(maxOnes, maxOnesInWindow);
        }

        return ones - maxOnes;
    }
};
