class NumArray {
private:
    vector<int> seg;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        seg.resize(4 * nums.size(), 0);

        buildSegmentTree(0, 0, nums.size()-1);
    }

    void buildSegmentTree(int index, int left, int right){
        if(left == right){
            seg[index] = nums[left];
            return;
        }

        int mid = left + (right-left)/2;
        
        buildSegmentTree(2*index+1, left, mid);
        buildSegmentTree(2*index+2, mid+1, right);

        seg[index] = seg[2*index+1] + seg[2*index+2];
    }
    
    void updateIndex(int index, int segIndex, int val, int left, int right){
        if(left == right){
            if(left == index){
                seg[segIndex] = val;
            }
            return;
        }

        int mid = left + (right - left)/2;

        if(index <= mid){
            updateIndex(index, 2*segIndex + 1 , val, left, mid);
        }else{
            updateIndex(index, 2*segIndex + 2, val, mid+1, right);
        }

        seg[segIndex] = seg[2*segIndex+1] + seg[2*segIndex+2];
    }

    void update(int index, int val) {
        updateIndex(index, 0, val, 0, nums.size()-1);
    }
    
    int getSumRange(int segIndex, int segLeft, int segRight, int left, int right){
        
        if(segLeft > right || segRight < left){
            return 0;
        }

        if(left <= segLeft && segRight <= right){
            return seg[segIndex];
        }


        int mid = segLeft + (segRight - segLeft)/2;
        return getSumRange(2*segIndex+1, segLeft, mid, left, right) + 
                getSumRange(2*segIndex+2, mid+1, segRight, left, right);
    }

    int sumRange(int left, int right) {
        return getSumRange(0, 0, nums.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */