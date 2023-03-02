class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i=0; i < stones.size(); i++){
            pq.push(stones[i]);
        }

        
        while(pq.size() > 1){
            int num1 = pq.top();
            pq.pop();

            int num2 = pq.top();
            pq.pop();

            if(num1 == num2){
                if(pq.size() == 0){     //if priority queue is empty at last return 0
                    pq.push(0);
                }
                continue;
            }
            else{
                int newNum = abs(num1 - num2);
                pq.push(newNum);
            }
        }

        return pq.top();
    }
};
