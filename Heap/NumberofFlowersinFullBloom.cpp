class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        unordered_map<int, queue<int>> map;
        priority_queue<int, vector<int>, greater<int>> start;
        priority_queue<int, vector<int>, greater<int>> end;


        for(int i=0; i < flowers.size(); i++){        //Created priority queue for starting and ending of flower section
            start.push(flowers[i][0]);
            end.push(flowers[i][1]);
        }


        for(int i=0; i < people.size(); i++){         //Creted map to keep track of original indexes of peoples
            map[people[i]].push(i);
        }

        sort(people.begin(), people.end());

        int count = 0;
        vector<int> ans(people.size(), 0);
                                                      //Current Available flower = total openings(till pos) - total closing(till pos)
        for(int i=0; i < people.size(); i++){         //find available flowers for perticular position as positions are in sorted order
            while(!start.empty() && start.top() <= people[i]){
                start.pop();
                count++;
            }

            while(!end.empty() && end.top() < people[i]){
                end.pop();
                count--;
            }

            ans[map[people[i]].front()] = count;
            map[people[i]].pop();                     //removing leadin index from hashmap so that we can update next index of same people position
        }

        return ans;

    }
};
