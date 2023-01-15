class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& events) {
        if(events.size() == 1){
            return 1;
        }
        sort(events.begin(), events.end(), compare);

        for(int i=0;i < events.size(); i++){
            cout<<events[i][0]<<" "<<events[i][1]<<endl;
        }

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
