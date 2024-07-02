class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char, int> map;
        int maxLen = 0;

        int left = 0;
        int currMax = 0;

        for(int right = 0; right < answerKey.size(); right++){
            map[answerKey[right]] += 1;
            currMax = max(currMax, map[answerKey[right]]);

            if((right-left+1) - currMax > k){
                map[answerKey[left]] -= 1;
                left++;
            }

            maxLen = max(maxLen, (right-left+1));
        }

        return maxLen;
    }
};
