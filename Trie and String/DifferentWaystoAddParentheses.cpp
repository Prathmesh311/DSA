class Solution {
public:
    unordered_map<string, vector<int>> dp;

    vector<int> diffWaysToCompute(string expression) {
        if(dp.find(expression) != dp.end()){
            return dp[expression];
        }

        vector<int> result;
        for(int i=0; i < expression.size(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                for(int leftNum : left){
                    for(int rightNum : right){
                        if(expression[i] == '+'){
                            result.push_back(leftNum + rightNum);
                        }else if(expression[i] == '-'){
                            result.push_back(leftNum - rightNum);
                        }else if(expression[i] == '*'){
                            result.push_back(leftNum * rightNum);
                        }
                    }
                }
            }
        }

        if(result.empty()){
            result.push_back(std::stoi(expression));
        }

        dp[expression] = result; // Cache the result
        return result;
    }
};
