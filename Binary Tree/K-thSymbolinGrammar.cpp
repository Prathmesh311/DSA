class Solution {
public:
    int kthGrammar(int n, int k) {
        int curr = 0;

        int left = 1;
        int right = pow(2, n-1);

        //Here we don't need to contruct whole string. It's like a tree so we can traverse through the tre and find the element at specific index and depth

        for(int i=0; i <= n-1; i++){  //using binary search to traverse through binary tree
            int mid = (left+right)/2;

            if(k <= mid){
                right = mid;
            }else{
                left = mid+1;
                curr = curr == 0 ? 1 : 0;
            }
        }

        return curr;
    }
};
