class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> tempSpan;
        stack<int> stack;


        for(int i=temperatures.size()-1; i >= 0; i--){
            if(stack.size() == 0){
                stack.push(i);
                tempSpan.push_back(0);
            }else{
                while(stack.size() > 0 && temperatures[i] >= temperatures[stack.top()]){
                    stack.pop();
                }

                if(stack.size() == 0){
                    stack.push(i);
                }

                int span = stack.top() - i;
                tempSpan.push_back(span);
                stack.push(i);
            }
        }

        reverse(tempSpan.begin(), tempSpan.end());
        
        return tempSpan;
    }
};
