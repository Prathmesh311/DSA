class Solution {
public:
    bool isPalindrome(string &s, int left, int right, int remDeletes){
        if(left > right){
            return true;
        }

        if(s[left] == s[right]){
            return isPalindrome(s, left+1, right-1, remDeletes);
        }else if(remDeletes){
            return isPalindrome(s, left, right-1, 0) || isPalindrome(s, left+1, right, 0);
        }else{
            return false;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        int remDeletes = 1;

        return isPalindrome(s, left, right, remDeletes);
    }
};
