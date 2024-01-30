class Solution {
public:
    void dfs(map<int, vector<pair<string, int>>> &wordComb, vector<string> &sentences, string possibleSentence, int index, int len){
        //if we can reach at last index, then push possible combination string to ans  
        if(index >= len){     
            possibleSentence.erase(possibleSentence.size()-1);
            sentences.push_back(possibleSentence);
            return;
        }

        vector<pair<string, int>> wordsAvailable = wordComb[index];

        //add current word in string and jump to next index in map
        for(auto p : wordsAvailable){         
            dfs(wordComb, sentences, possibleSentence + p.first + " ", p.second, len);  
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> sentences;
        vector<bool> dp(s.size()+1, false);
        map<int, vector<pair<string, int>>> wordComb;
        

        dp[s.size()] = true; //Make last position true to check if we can reach their
        for(int i=s.size(); i >= 0; i--){
            for(string word : wordDict){    //iterate in reverse order and store word end index true/false
                if(i + word.size() <= s.size() && s.substr(i, word.size()) == word){
                    dp[i] = dp[i + word.size()];
                    wordComb[i].push_back({word, i + word.size()});     //storing words that can be formed at index i and next words starting index for keeping track of possible word combinations.
                }
            }
        }

        //dfs over word combinatins and store possible combinatins that are forming
        string possibleSentence = "";
        dfs(wordComb, sentences, possibleSentence,  0, s.size());   

        return sentences;
    }
};
