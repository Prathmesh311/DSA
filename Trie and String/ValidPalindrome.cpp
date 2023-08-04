class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;

        while(start <= end){

            if(!iswalnum(s[start])){      //checking if char is alphanumeric or not
                start++;
            }
            else if(!iswalnum(s[end])){   //checking if char is alphanumeric or not
                end--;
            }
            else if(tolower(s[start]) == tolower(s[end])){
                start++;
                end--;
            }
            else if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
        }

        return true;
    }
};
