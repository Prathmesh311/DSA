class Solution {
public:
    int Lo;
    int maxPal;

    void extendPalindrom(string s, int j, int k)
    {
        while(j >= 0 && k < s.size() && s[j] == s[k])
        {
            j--;
            k++;
        }
        if(maxPal < k-j-1)
        {
            Lo = j+1;
            maxPal = k-j-1;
        }
    }

    string longestPalindrome(string s) {
        if(s.size() < 2)
        {
            return s;
        }
        
        for(int i=0; i < s.size(); i++)
        {
            extendPalindrom(s, i, i);
            extendPalindrom(s, i, i+1);
        }

        return s.substr(Lo,  maxPal);
    }
};
