class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int totalCount = 0;
        int MOD = 1000000007;

        sort(arr.begin(), arr.end());

        for(int i=0; i < arr.size(); i++){
            int remTarget = target - arr[i];
            
            int left = i+1;
            int right = arr.size()-1;

            while(left < right){
                int currSum = arr[left] + arr[right];

                if(remTarget == currSum){
                    if(arr[left] == arr[right]){
                        int count = right - left + 1;
                        totalCount += count * (count - 1) / 2;
                        totalCount %= MOD;
                        break;
                    }else{
                        int leftCount = 1; 
                        int rightCount = 1;

                        while(left < right && arr[left] == arr[left+1]){
                            left++;
                            leftCount++;
                        }

                        while(left < right && arr[right] == arr[right-1]){
                            right--;
                            rightCount++;
                        }

                        totalCount += leftCount * rightCount;
                        totalCount %= MOD;
                        left++;
                        right--;
                    }
                }else if(currSum > remTarget){
                    right--;
                }else{
                    left++;
                }
            }
        }

        return totalCount;
    }
};
