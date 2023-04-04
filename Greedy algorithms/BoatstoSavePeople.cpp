class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int totalBoats = 0;
        int low = 0;
        int high = people.size()-1;

        sort(people.begin(), people.end());

        while(low <= high){
            totalBoats++;
            if(people[low] + people[high] <= limit){
                low++;
            }
            high--;
        }

        return totalBoats;
        
    }
};
