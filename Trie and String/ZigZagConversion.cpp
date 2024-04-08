class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        
        string result = "";
        set<int> set;

        int jump = 2 * (numRows - 1);
        for(int i=0; i < numRows; i++){
            int currJump = 2 * (numRows - i - 1);
            currJump = abs(jump - currJump);

            for(int j = i; j < s.size(); j = j + currJump){
                if(set.find(j) == set.end()){
                    result += s[j];
                    set.insert(j);
                }
                currJump = abs(jump - currJump);
            }
            set.clear();
        }

        return result;
    }
};
