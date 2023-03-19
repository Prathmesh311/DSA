class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> stack;

        for(int i=0; i < asteroids.size(); i++){

            if(asteroids[i] >= 0 || stack.empty()){
                stack.push(asteroids[i]);
            }
            else{
                while(!stack.empty() && stack.top() > 0 && stack.top() < abs(asteroids[i])){
                    stack.pop();
                }

                if(!stack.empty() && stack.top() == abs(asteroids[i])){
                    stack.pop();
                }
                else{
                    if(stack.empty() || stack.top() < 0){
                        stack.push(asteroids[i]);
                    }
                }
            }
            
        }

        while(!stack.empty()){
            ans.insert(ans.begin(), stack.top());
            stack.pop();
        }

        return ans;

        
    }
};
