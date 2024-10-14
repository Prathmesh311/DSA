class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long maxScore = 0;

        priority_queue<int> pq;

        for(int i=0; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        while(k > 0 && !pq.empty()){
            auto v = pq.top();
            pq.pop();


            int currNum = v;
            maxScore += (long long) currNum;

            int rem = currNum % 3;
            currNum = currNum/3;

            if(rem > 0){
                currNum++;
            }

            pq.push(currNum);
            k--;
        }

        return maxScore;
    }
};
