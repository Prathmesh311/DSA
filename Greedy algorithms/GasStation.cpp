class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0;
        int totalRem = 0;

        for(int i=0; i < gas.size(); i++){
            totalRem += gas[i] - cost[i];
        }

        if(totalRem < 0){        //If total Of diff is less than 0 no path exist
            return -1;
        }

        int total = 0;
        for(int i=0; i < gas.size(); i++){  If you reach at the end of array without loosing gas. Return index of 1st starting position. 
            total += gas[i] - cost[i];

            if(total < 0){
                total = 0;
                index = i+1;
            }
        }

        return index;
    }
};
