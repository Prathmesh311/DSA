class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreater(nums2.size());
        vector<int> ans(nums1.size());

        stack<int> s;
       
        for(int i=nums2.size()-1; i >= 0; i--){
            int curr = nums2[i];
            while(!s.empty() && s.top() <= curr){    //poping stack until next greater element found
                s.pop();
            }

            if(s.empty()){
                nextGreater[i] = -1;
            }else{
                nextGreater[i] = s.top();
            }

            s.push(curr);                           
        }

        //Aligning ans format
        for(int i=0; i < nums1.size(); i++){
            for(int j=0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    ans[i] = nextGreater[j];
                }
            }
           
        }
       
        return ans;
      
    }
};
