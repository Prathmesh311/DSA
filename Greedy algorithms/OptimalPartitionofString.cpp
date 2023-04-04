class Solution {
public:
    int partitionString(string s) {
        map<char, int> map;
        int totalPartitions = 0;

        for(int i=0; i < s.size(); i++){
            if(map.find(s[i]) == map.end()){
                map[s[i]] = 1;
            }
            else{
                totalPartitions++;
                map.clear();
                map[s[i]] = 1;
            }
        }

        return totalPartitions + 1;
    }
};
