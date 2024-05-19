class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> stack;
        vector<int> canSee(heights.size(), 0);

        for(int i=0; i < heights.size(); i++){
            while(!stack.empty() && heights[stack.top()] < heights[i]){
                int topIndex = stack.top();
                stack.pop();

                canSee[topIndex] += 1;
            }

            if(stack.size()){
                canSee[stack.top()] += 1;
            }

            stack.push(i);
        }

        return canSee;
    }
};
