class Solution {
public:
    int getStepsInSubtree(long long currNum, long long s, long long n){
        int currSteps = 0;

        long long nei = currNum + 1;
        while(currNum <= n){
            currSteps += min(nei, n+1) - currNum;
            currNum *= 10;
            nei *= 10;            
        }

        return (int)currSteps;
    }

    int findKthNumber(int n, int k) {
        int s = 1;
        long long currNum = 1;

        while(s < k){
            int steps = getStepsInSubtree(currNum, s, n);

            if(s + steps <= k){
                currNum = currNum+1;
                s += steps;
            }else{
                currNum *= 10;
                s += 1;
            }
        }

        return (int)currNum;
    }
};
