class Solution {
public:
    int sum = 0;
    int traversal(int n, vector<int>& cost, vector<int>& pathSum, int i){
        if(i > n){
            return 0;
        }
         
        int left = traversal(n, cost, pathSum, 2*i);
        int right = traversal(n, cost, pathSum, (2*i)+1);

        if(left != right){
            sum += abs(left - right);
        }

        return max(left, right) + cost[i-1];
    }
    
    
    int minIncrements(int n, vector<int>& cost) {
        vector<int> pathSum;
        int total =  traversal(n, cost, pathSum, 1);
        return sum;
       
    }
};
