class Solution {
public:

    int numPalindrome(string s, int left, int right){
        int totalPali = 0;

        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            totalPali++;
        }

        return totalPali;
    }


    int countSubstrings(string s) {
        int totalPalindromes = 0;

        for(int i = 0; i < s.size(); i++){
            totalPalindromes += numPalindrome(s, i, i);

            if(i + 1 < s.size()){
                totalPalindromes += numPalindrome(s, i, i+1);
            }
        }

        return totalPalindromes;
    }
};
