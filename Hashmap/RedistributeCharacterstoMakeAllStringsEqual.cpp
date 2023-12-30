class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> map;

        for(string word: words){
            for(char c : word){
                map[c] += 1;
            }
        }

        for(auto p : map){
            if(p.second % words.size() != 0){
                return false;
            }
        }
        
        return true;
    }
};
