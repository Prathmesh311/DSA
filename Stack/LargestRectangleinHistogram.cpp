class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stack;
        int globalMin = heights[0];
        int maxArea = 0;
        int len = heights.size();

        //Method 1 : Optimal Method using Stack
        for(int i = 0; i < heights.size(); i++){
            int start = i;

            while(!stack.empty() && heights[i] <= stack.top().second){
                pair<int, int> p = stack.top();
                stack.pop();
                maxArea = max(maxArea, (i-p.first) * p.second);
                start = p.first;
            }

            stack.push({start, heights[i]});      
        }


        while(!stack.empty()){
            pair<int, int> p = stack.top();
            stack.pop();
            maxArea = max(maxArea, p.second * (len - p.first));
        }


        //Method 2 : brute Force apporach give TLE
        for(int i = 0; i < heights.size(); i++){
            int currMin = heights[i];
            globalMin = min(globalMin, heights[i]);

            for(int j = i; j >=0; j--){
                currMin = min(currMin, heights[j]);
                
                int currArea;

                if(currMin == globalMin){
                    currArea = (i+1) * globalMin;
                    maxArea = max(maxArea, currArea);
                    //cout<<i<<"-"<<j<<":"<<maxArea<<endl;
                    break;
                }
                else{
                    currArea = (i-j+1) * currMin;
                    maxArea = max(maxArea, currArea);
                    //cout<<i<<"-"<<j<<":"<<maxArea<<endl;
                }
                
            }
        }

        return maxArea;
    }
};
