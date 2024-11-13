/*

logs = ["0:start:1", "1:start:2", "1:end:4, "0:end:7"]
excTime = [4, 3]

*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> exTime(n, 0);
        stack<pair<int, int>> stack;

        int timeDiff = 0;

        for(string log : logs){
            stringstream ss(log);
            string temp, action, temp3;

            getline(ss, temp, ':');
            getline(ss, action, ':');
            getline(ss, temp3, ':');

            int funcID = stoi(temp);
            int timestamp = stoi(temp3);


            if(action == "start"){
                if(!stack.empty()){
                    exTime[stack.top().first] += timestamp - stack.top().second;
                }

                stack.push({funcID, timestamp});
            }else{
                auto p  = stack.top();
                stack.pop();

                int timeTaken = timestamp - p.second + 1;
                exTime[p.first] += timeTaken;

                if(!stack.empty()){
                    stack.top().second = timestamp + 1;
                }
            }
        }

        return exTime;
    }
};
