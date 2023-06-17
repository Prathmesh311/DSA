class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        vector<int> newInterval;

        sort(intervals.begin(), intervals.end());

        for(int i=0; i < intervals.size(); i++){
            int intervalStart = intervals[i][0];     //store starting of interval
            int maxEnd = intervals[i][1];            //use to store max end point of interval till now;


            while(i < intervals.size()){
                if(i+1 < intervals.size() && maxEnd >= intervals[i+1][0]){      //check if starting of interval is less than or equal to max interval end
                    maxEnd =max(maxEnd, intervals[i+1][1]);                     //update max interval end point.
                    i++;
                }
                else{
                    maxEnd = max(maxEnd, intervals[i][1]);      
                    break;
                }
            }

            newInterval = {intervalStart, maxEnd};             //pushed merged or unmerged intervals
            merged.push_back(newInterval);
        }


        return merged; 
    }
};
