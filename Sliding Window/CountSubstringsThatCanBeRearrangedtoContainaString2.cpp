class Solution {
public:
    bool inValid(unordered_map<char, int> &countMap, unordered_map<char, int> &ref){
        for(auto p : ref){
            if(countMap[p.first] < p.second){
                return true;
            }           
        }
        return false;
    }

    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> ref;
        unordered_map<char, int> countMap;

        for(char c : word2){
            ref[c] += 1;
        }

        long long subArrays = 0;

        int left = 0;
        for(int right = 0; right < word1.size(); right++){
            char currChar = word1[right];

            countMap[currChar] += 1;

            if(ref.find(currChar) != ref.end() && countMap[currChar] >= ref[currChar] && !inValid(countMap, ref)){
                while(true && left <= right){
                    subArrays += word1.size() - right;

                    char leftChar= word1[left];
                    countMap[leftChar] -= 1;
                    left++;

                    if(ref.find(leftChar) == ref.end()){
                        continue;
                    } 
                    if(countMap[leftChar] < ref[leftChar]){
                        break;
                    }
                }
            }          
        }

        return subArrays;
    }
};
