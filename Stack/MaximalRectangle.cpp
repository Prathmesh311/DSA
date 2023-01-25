class Solution {
private:
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

    
public:
    int maximalRectangle(vector<vector<char>>& M) {
        vector<vector<int>> matrix(M.size(), vector<int> (M[0].size(), 0));

        for(int i=0; i < M.size(); i++){
            for(int j=0; j < M[0].size(); j++){
               matrix[i][j] = int(M[i][j]) - '0';
            }
        }

        //compute area of 1st row
        int area = largestRectangleArea(matrix[0]);

        for(int i=1; i < matrix.size(); i++){
            for(int j=0; j < matrix[0].size(); j++){
                //row update: by adding previous row value
                if(matrix[i][j] != 0){
                    matrix[i][j] = matrix[i][j] + matrix[i-1][j];
                }else{
                    matrix[i][j] = 0;
                }
            }

            area = max(area, largestRectangleArea(matrix[i]));
        }

        return area;
    }
};
