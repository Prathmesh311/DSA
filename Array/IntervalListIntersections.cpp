class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        int firstIndex = 0;
        int secondIndex = 0;

        while(firstIndex < firstList.size() && secondIndex < secondList.size()){
            int currStart = max(firstList[firstIndex][0], secondList[secondIndex][0]);
            int currEnd = min(firstList[firstIndex][1], secondList[secondIndex][1]);

            if(currStart <= currEnd){
                result.push_back({currStart, currEnd});
            }

                if(firstList[firstIndex][1] <= secondList[secondIndex][1]){
                    firstIndex++;
                }else{
                    secondIndex++;
                }
        }

        return result;
    }
};
