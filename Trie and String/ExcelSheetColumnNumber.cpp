class Solution {
public:
    int titleToNumber(string columnTitle) {
        int colNumber = 0;
      
        for(char c : columnTitle)
        {
			      int d = c - 'A' + 1;
            colNumber = colNumber * 26 + d;
        }

        return colNumber;       
    }
};
