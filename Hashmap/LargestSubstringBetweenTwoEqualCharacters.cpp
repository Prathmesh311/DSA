class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int longestDiff = -1;

        unordered_map<char, int> map;

        for(int i=0; i < s.size(); i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = i;
            }else{
                int currDiff = i - map[s[i]] - 1;
                longestDiff = max(longestDiff, currDiff);
            }
        }

        return longestDiff;
    }
};
