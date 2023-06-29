class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        set<string> set;                       //using set to check same string is not allocated to different chars in pattern
        string word;

        stringstream X(s);

        int i = 0;
        while(getline(X, word, ' ')){
            
            if(map.find(pattern[i]) == map.end() && set.find(word) == set.end()){  //Adding char and string to hashmap at 1st occurance
                map[pattern[i]] = word;
                set.insert(word);
            }
            else{
                if(map[pattern[i]] != word || set.find(word) == set.end()){        //If string is previously  allocated to diff char return false
                    return false;
                }
            }
            i++;
        }

        if(i < pattern.size()){     //if length of words in s is less than patterns return false
            return false;
        }

        return true;
    }
};
