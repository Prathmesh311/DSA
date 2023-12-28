class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
       
        map<int, int> map;
        for(int num : hand){
            map[num] += 1;
        }

        while(!map.empty()){
            int count = 0;
            int check = 0;
            int prevNum;

            for(auto p : map){
                if(check == 1 && p.first - prevNum != 1){
                    return false;
                }

                if(p.second == 1){
                    map.erase(p.first);
                }else{
                    map[p.first] -= 1;
                }

                count++;
                prevNum = p.first;
                check = 1;

                if(count == groupSize){
                    break;
                }
            }

            if(count != groupSize){
                return false;
            }
        }
       
        return true;
    }
};
