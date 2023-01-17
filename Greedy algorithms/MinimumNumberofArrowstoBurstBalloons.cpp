class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), compare);

        int counter = 1;
        int lastEnd = events[0][1];

        for(int i=1; i < events.size(); i++){
            if(events[i][0] > lastEnd){
                lastEnd = events[i][1];
                counter++;
            }
        }
        return counter;
    }
};
