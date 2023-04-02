class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[301] = {false};
        dp[s.size()] = true;

        for(int i = s.size()-1; i >= 0; i--){   //Traversing in reverse order in given string
            for(string word : wordDict){        //Traversing through all words in dictionary
                if((i + word.size()) <= s.size() && s.substr(i,  word.size()) == word){ // if word from dictionary matches word in given string
                    dp[i] = dp[i + word.size()];  //store word end +1 state (helps in determining whether we can take all of the given string)
                }
                if(dp[i]){
                    break;
                }
            }
        }
      
        return dp[0];
    }
};
