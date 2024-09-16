class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<double> times;

        for(string str : timePoints){
            int currValue = std::stoi(str.substr(0,2)) * 60;
            currValue += std::stoi(str.substr(3,2));
            times.push_back(currValue);
        }

        sort(times.begin(), times.end());
        times.push_back(times[0] + 1440);


        int minDiff = 24 * 60;
        for(int i=0; i < times.size()-1; i++){
            int currDiff = times[i+1] - times[i];
            minDiff = min(minDiff, currDiff);
        }

        return minDiff;
    }
};
