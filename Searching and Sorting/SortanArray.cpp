class Solution {
public:
    
    void merge(vector<int>& nums, int start,  int end){
        vector<int> temp(end-start+1);
 
        int mid = (start+end)/2;
        int i = start;
        int j = mid+1;
        int k = 0;
        
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }
        
        
        while(i <= mid){
            temp[k++] = nums[i++];
        }
        while(j <= end){
            temp[k++] = nums[j++];
        }
        
        
        int l=0;
        for(int i=start; i <= end; i++){
            nums[i] = temp[l];
            l++;
        }
        
        return;
    }
    
    void mergeSort(vector<int>& nums, int start, int end){
        //Base case
        if(start >= end){
            return;
        }
        
        //Recursive case
        int mid = (start + end)/2;
        
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
       
        merge(nums, start, end);
    }
    
    
    void quickSort(vector<int>& nums, int start, int end){
        //Base case
        if(start >= end){
            return;
        }
        
        
        //Recursive case
        int pivot = nums[end];
        
        int i=start-1;
        int j=start;
        for(int j = start; j< end; j++){
            if(nums[j] < pivot){
                swap(nums[i+1], nums[j]);
                i++;
              
            }
           
           
        }
        swap(nums[i+1], nums[end]);
        int mid = i+1;
        
            
        quickSort(nums, start, mid-1);
        quickSort(nums, mid+1, end);
        
        
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
       
        mergeSort(nums, 0, nums.size()-1);
        cout<<nums.size()-1;
        //quickSort(nums, 0, nums.size()-1);
        
        return nums;
    }
};
