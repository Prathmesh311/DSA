class Solution {
public:
    int beautySum(string s) {
        unordered_map<char, int> count;
        int totalBeauty = 0;

        for(int i=0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                count[s[j]] += 1;

                if(count.size() >= 2){
                    int maxCount = 0;
                    int minCount = INT_MAX;
                    for(auto p : count){
                        maxCount = max(maxCount, p.second);
                        minCount = min(minCount, p.second);
                    }

                    totalBeauty += maxCount - minCount;
                }
            }
            count.clear();
        }


        return totalBeauty;
    }
};
