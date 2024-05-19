class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        vector<int> waitDays(temperatures.size(), 0);

        for(int i=0; i < temperatures.size(); i++){

            while(!stack.empty() && temperatures[stack.top()] < temperatures[i]){
                int topIndex = stack.top();
                stack.pop();

                waitDays[topIndex] = i - topIndex;
            }
            
            stack.push(i);
        }

        return waitDays;
    }
};
