class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxTurbulance = 0;
        int currTurbulance = 1;
        int pos = -1;

        for(int i=1; i < arr.size(); i++){
            if(i == 1){
                if(arr[i-1] < arr[i]){
                    pos = 1;
                    currTurbulance++;
                }else if(arr[i-1] > arr[i]){
                    pos = 0;
                    currTurbulance++;
                }else{
                    pos = -1;
                    currTurbulance = 1;
                }
            }
            else if(arr[i-1] < arr[i]){
                    if(pos == 0){
                        currTurbulance++;
                    }else{
                        currTurbulance = 2;
                    }
                    pos = 1;
            }else if(arr[i-1] > arr[i]){
                    if(pos == 1){
                        currTurbulance++;
                    }else{
                        currTurbulance = 2;
                    }
                    pos = 0;
            }else{
                pos = -1;
                currTurbulance = 1;
            }

            maxTurbulance = max(maxTurbulance, currTurbulance);
        }
        maxTurbulance = max(maxTurbulance, currTurbulance);

        return maxTurbulance;
    }
};
