class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        stack<vector<int>> stack;
        vector<vector<int>> survivedRobots;

        vector<vector<int>> robots;

        for(int i=0; i < positions.size(); i++){
            robots.push_back({positions[i], health[i], directions[i] == 'R' ? 1 : -1, i});
        }

        sort(robots.begin(), robots.end());

        for(int i=0; i < robots.size(); i++){
            if(robots[i][2] == 1){
                stack.push({robots[i][1], robots[i][3]});
            }else{
                int leftHealth = robots[i][1];

                while(!stack.empty()){
                    vector<int> v = stack.top();
                    int healthTop = v[0];
                    stack.pop();

                    if(healthTop == leftHealth){
                        leftHealth = -1;
                        break;
                    }else if(healthTop > leftHealth){
                        stack.push({healthTop-1, v[1]});
                        break;
                    }
                    
                    leftHealth--;
                }

                if(stack.empty() && leftHealth != -1){
                    survivedRobots.push_back({robots[i][3] , leftHealth});
                }
            }
        }
        
        while(!stack.empty()){
            vector<int> v = stack.top();
            survivedRobots.push_back({v[1], v[0]});
            stack.pop();
        }

        sort(survivedRobots.begin(), survivedRobots.end());

        vector<int> result;
        for(vector v: survivedRobots){
            result.push_back(v[1]);
        }

        return result;
    }
};
