class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0;
        int right = people.size()-1;

        sort(people.begin(), people.end());

        int currLimit = limit;
        int boats = 0;

        while(left <= right){
            if(people[right] <= currLimit){
                currLimit -= people[right];
                right--;
            }

            if(people[left] <= currLimit){
                left++;
            }

            currLimit = limit;
            boats++;
        }

        return boats;
    }
};
