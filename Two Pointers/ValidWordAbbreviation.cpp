/*
word = "pr0athmesh"
abbr = "pr02hme2"


time  = O(max(n, m))
space =  O(1)
*/

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int indexW = 0;
        int indexA = 0;

        while(indexW < word.size() && indexA < abbr.size()){
            
            if(isdigit(abbr[indexA])){
                if(abbr[indexA] == '0'){
                    if(word[indexW] == abbr[indexA]){
                        indexW++;
                        indexA++;
                        continue;
                    }else{
                        return false;
                    }
                }

                int currNum = 0;
                while(isdigit(abbr[indexA])){
                    currNum = currNum * 10 + (abbr[indexA] - '0');
                    indexA++;
                }

                indexW += currNum;
            }else if(word[indexW] == abbr[indexA]){
                indexW++;
                indexA++;
            }else{
                return false;
            }
        }

        return indexW == word.size() && indexA == abbr.size();
    }
};
