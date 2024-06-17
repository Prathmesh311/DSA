class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;
        unordered_map<char, int> temp;

        int counter = s1.size();
        int start = 0;
        int end = 0;

        for(char c : s1){
            map[c] += 1;
            temp[c] += 1;
        }

        while(end < s2.size()){
            if(temp.find(s2[end]) != temp.end()){
                if(temp[s2[end]] > 0){
                    counter--;
                    temp[s2[end]]--;

                    if(counter == 0){
                        return true;
                    }
                    end++;
                }else{

                    while(temp[s2[end]] <= 0 && start < end){
                        temp[s2[start]]++;
                        counter++;
                        start++;
                    }
                }
            }
            else{
                counter = s1.size();
                temp = map;
                end++;
                start = end;
            }
        }   

        return false;
    }
};
