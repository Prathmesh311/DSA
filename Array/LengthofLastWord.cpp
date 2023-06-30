class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;

        int lastWordLength = 0;
        while(getline(ss, word, ' ')){
            if(word.size() != 0){
                lastWordLength = word.size();
            }
        }

        return lastWordLength;
    }
};
