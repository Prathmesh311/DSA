class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int size = nums.size();
        vector<int> visited(size, 0);

        for(int i=0; i < size; i++){
            if(visited[i] == 1){
                continue;
            }

            int slow = i;
            int fast = i;

            visited[i] = 1;

            bool forward = nums[fast] > 0;
            int check = 0;

            do{
                slow = (((slow + nums[slow]) % size + size) % size);
                visited[slow] = 1;

                fast = (((fast + nums[fast]) % size + size) % size);
                if(forward != nums[fast] > 0){
                    check = 1;
                    break;
                }
                visited[fast] = 1;
                
                fast = (((fast + nums[fast]) % size + size) % size);
                if(forward != nums[fast] > 0){
                    check = 1;
                    break;
                }
                visited[fast] = 1;
            }while(slow != fast);

            if(check == 1){
                continue;
            }

            if(slow == slow && slow != (((slow + nums[slow]) % size + size) % size)){
                return true;
            }
        }

        return false;
    }
};
