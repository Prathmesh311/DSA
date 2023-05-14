class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        int arr[51] = {0};
        vector<int> ans;
        
        int i=1;
        int round = 1;
        arr[1] = 1;
        
        while(true){
            int num = i;
            
            int nextNum = num + round*k;
            if(nextNum > n){
                nextNum = nextNum % n;
                if(nextNum == 0){
                    nextNum = n;
                }
            }
            
            arr[nextNum] = arr[nextNum] + 1;  
            if(arr[nextNum] == 2){
                break;
            }
            
            round++;
            i = nextNum;
        }
        
        for(int i=1; i <= n; i++){
            if(arr[i] == 0){
                ans.push_back(i);
            }
        }
          
        return ans;
    }
};
