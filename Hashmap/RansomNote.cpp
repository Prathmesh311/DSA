class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;

        for(char c : magazine){              //creating hashtable of char, occurances
            map[c] += 1;
        }

        for(char c : ransomNote){
            if(map.find(c) != map.end()){    //for each occurance of char reduce count by 1;
                if(map[c] == 0){
                    return false;
                }
                map[c] -= 1;
            }
            else{
                return false;
            }
        }

        return true;
    }
};
