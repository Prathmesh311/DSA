class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;

        for(int num : nums){
            pq.push(num);
        }

        int max = pq.top();
        pq.pop();
        int secondMax = pq.top();

        return (max-1) * (secondMax - 1);
    }
};
