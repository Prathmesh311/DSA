class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& heights, int n) {
        vector<int> nextSmaller(heights.size());

        stack<int> s;
       
        for(int i=heights.size()-1; i >= 0; i--){
            int curr = heights[i];
            while(!s.empty() && heights[s.top()] >= curr){    //poping stack until next smaller element found
                s.pop();
            }

            if(s.empty()){
                nextSmaller[i] = -1;
            }else{
                nextSmaller[i] = s.top();                    //Storing next smaller elements index
            }

            s.push(i);                           
        }

        return nextSmaller;
    }

    vector<int> prevSmallerElement(vector<int>& heights, int n) {
        vector<int> nextSmaller(heights.size());

        stack<int> s;
       
        for(int i=0; i <= heights.size()-1; i++){
            int curr = heights[i];
            while(!s.empty() && heights[s.top()] >= curr){    //poping stack until next smaller element found
                s.pop();
            }

            if(s.empty()){
                nextSmaller[i] = -1;
            }else{
                nextSmaller[i] = s.top();                     //Storing next smaller elements index
            }

            s.push(i);                           
        }

        return nextSmaller;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prev;
        prev = prevSmallerElement(heights, n);

        vector<int> next;
        next = nextSmallerElement(heights, n);


        int maxArea = INT_MIN;
        for(int i=0; i < n; i++){
            int l = heights[i];

            if(next[i] == -1){
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;

            int newArea = l * b;
            maxArea = max(maxArea, newArea);
        }
        

        return maxArea;
    }
};
