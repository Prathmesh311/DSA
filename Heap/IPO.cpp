class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //** Using Map and PQ :- logic was correct but giving TLE
        // map<int, priority_queue<int>> projects;

        // for(int i=0; i < profits.size(); i++){
        //     projects[capital[i]].push(profits[i]);
        // }

        // while(k > 0 && !projects.empty()){
        //     int maxProfit = 0;
        //     int capitalToTake = -1;
            
        //     for(auto p : projects){
        //         if(p.first <= w && !projects[p.first].empty()){
        //             int currProfit = projects[p.first].top();
        //             if(maxProfit < currProfit){
        //                 maxProfit = currProfit;
        //                 capitalToTake = p.first;
        //             }
        //         }
        //     }

        //     if (capitalToTake == -1) break;


        //     w = w + projects[capitalToTake].top();
        //     projects[capitalToTake].pop();

        //     k--;
        // }

        // return w;


        //Method-2: using 2 PQ's
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> projects;

        for(int i=0; i < profits.size(); i++){            //created min PQ for taking smllest capital first
            projects.push({capital[i], profits[i]});
        }

        //PQ for maxProfit we can take from projects which can be done in w
        priority_queue<int> maxProfits;        

        while(k > 0){
            //Add projects atainable with w
            while(!projects.empty() && projects.top().first <= w){
                maxProfits.push(projects.top().second);
                projects.pop();
            }

            if(maxProfits.empty()){
                break;
            }

            //Take max amount of profit from available projects
            w += maxProfits.top();
            maxProfits.pop();

            k--;
        }

        return w;
    }
};
