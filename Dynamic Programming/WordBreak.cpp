class Solution {
public:
    bool findBreak(string &s, map<string, bool> &dict, vector<bool> &dp, int start, int index){
        if(index >= s.size()){
            if(index == s.size()){
                string breakString = s.substr(start, index-start);
                if(dict.find(breakString) != dict.end()){
                    return dp[start] = true;
                }
            }
            return dp[start] = false;
        }

        if(dp[start]){
            return dp[start];
        }

        string breakString = s.substr(start, index-start);

        bool cut = false;
        bool pass = false;

        if(dict.find(breakString) != dict.end()){
            if(findBreak(s, dict, dp, index, index+1) || findBreak(s, dict, dp, start, index+1)){
                return dp[start] = true;
            }
        }else{
            pass = findBreak(s, dict, dp, start, index+1);
        }

        if(cut || pass){
            return dp[start] = true;
        }

        return dp[start] = false;

    }



    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        map<string, bool> dict;

        for(string str : wordDict){
            dict[str] = true;
        }

        //Optimal solution
        dp[s.size()] = true;
        for(int i = s.size(); i >=0 ; i--){
            if(dp[i]){
                for(auto p : dict){
                    int len = p.first.size();
                    if(i-len >= 0 && s.substr(i - len, len) == p.first){
                        cout<<i-len<<" "<<s.substr(i - len, len)<<endl;
                        dp[i-len] = true;
                    }
                }
            }
        }

        return dp[0];
        
        //return findBreak(s, dict, dp, 0, 1);
    }

    // optimal solution    
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
