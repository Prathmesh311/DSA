class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }


    int atMostVowels(string word, int goal){
        unordered_map<char, int> map;
        int subArrays = 0;

        int left = 0;
        
        for(int right = 0; right < word.size(); right++){
            if(!isVowel(word[right])){
                map.clear();
                left = right + 1;
                continue;
            }

            map[word[right]] += 1;

            while(left < right && map.size() > goal){
                map[word[left]] -= 1;
                if(map[word[left]] == 0){
                    map.erase(word[left]);
                }
                left++;
            }

            subArrays += right - left + 1;
        }
        return subArrays;
    }

    int countVowelSubstrings(string word) {
        return atMostVowels(word, 5) - atMostVowels(word, 4);
    }
};
