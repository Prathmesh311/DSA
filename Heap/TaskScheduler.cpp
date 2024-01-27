class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        map<char, int> map;

        for(int c : tasks){       //counting occurances of char in task
            map[c] += 1;
        }

        for(auto p : map){         
            pq.push(p.second);    //adding counting to pq
        }

        map.clear();

      
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;

            //peek max element from pq reduce by 1 and add to q 
            if(!pq.empty()){               
                int currNum = pq.top();
                pq.pop();
                 
                currNum--;
                if(currNum > 0){
                    q.push({currNum, time + n});
                }
            }
            
            //When clock comes to time add element from q to pq inorder to again peek by CPU
            if(!q.empty() && q.front().second == time){      
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
