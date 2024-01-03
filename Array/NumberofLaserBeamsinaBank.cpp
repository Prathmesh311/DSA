class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;
        int prevCount = 0;

        for(string lasers : bank){
            int currCount = 0;
            for(int i=0; i < lasers.size(); i++){
                if(lasers[i] == '1'){
                    currCount++;
                }
            }

            if(currCount != 0){
                totalBeams += currCount * prevCount;
                prevCount = currCount;
            }
        }

        return totalBeams;
    }
};
