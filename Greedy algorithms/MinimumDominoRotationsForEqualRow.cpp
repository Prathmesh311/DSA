class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> count(7, 0);
        int minSwaps = INT_MAX;

        for(int num : {tops[0], bottoms[0]}){

                bool value = true;
                int topCount = 0;
                int bottomCount = 0;

                for(int i = 0; i < tops.size(); i++){
                    if(tops[i] != num &&  bottoms[i] != num){
                        value = false;
                        break;
                    }else if(bottoms[i] != num){
                            bottomCount++;
                    }else if(tops[i] != num){
                            topCount++;
                    }
                }
                
                if(value){
                    minSwaps = min(minSwaps, min(topCount, bottomCount));
                }
        }

        return minSwaps == INT_MAX ? -1 : minSwaps;
    }
};
