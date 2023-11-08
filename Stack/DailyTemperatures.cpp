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

    //Easier method faster than above method
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stack;

        stack.push(0);

        for(int i=1; i < n; i++){
           
            while(!stack.empty() && temperatures[i] > temperatures[stack.top()]){
                ans[stack.top()] = i - stack.top();
                stack.pop();
            }


            stack.push(i);
        }

        return ans;
    }
};


