class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = 100000000000001;

        long long ansTillNow = 0;

        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long currTrips = 0;

            for(int i=0; i < time.size(); i++){
                currTrips += mid / time[i]; 
            }

            if(currTrips >= totalTrips){
                right = mid - 1;
                ansTillNow = mid;
            }
            else{
                left = mid+1;
            }
        }

        return ansTillNow;
    }
};
