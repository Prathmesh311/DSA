class NumArray {
public:
    vector<int> tree;
    int size = 0;

    NumArray(vector<int>& nums) {
        tree  = vector<int>(4*nums.size()+1, -1);
        this->size = nums.size();

        createTree(tree, nums, 0, 0, nums.size()-1);
    }

    void createTree(vector<int> &tree, vector<int> &nums, int index, int left, int right){
        if(left > right){
            return;
        }

        if(right == left){
            tree[index] = nums[right];
            return;
        }

        int mid = left + (right - left) / 2;

        createTree(tree, nums, 2*index + 1, left, mid);
        createTree(tree, nums, 2*index + 2, mid+1, right);

        tree[index] = tree[2*index + 1] + tree[2*index + 2];
    }

    void updatePos(int index, int pos, int treeLeft, int treeRight, int val){
        if (pos < treeLeft || pos > treeRight) return;

        if(treeLeft == treeRight){
            if(pos == treeLeft){
                tree[index] = val;
                return;
            } 
        }

    
        int mid = treeLeft + (treeRight - treeLeft) / 2;

        updatePos(2*index + 1, pos, treeLeft, mid, val);
        updatePos(2*index + 2, pos, mid+1, treeRight, val);

        tree[index] = tree[2*index + 1] + tree[2*index + 2];
    }
    
    void update(int index, int val) {
        updatePos(0, index, 0, size-1, val);
    }

    int findSumRange(int index, int treeLeft, int treeRight, int left, int right){
        if(treeLeft >= left && right >= treeRight){
            return tree[index];
        }

        if(treeRight < left || right < treeLeft){
            return 0;
        }

        int mid = treeLeft + (treeRight- treeLeft) / 2;
        int leftSum = findSumRange(2*index + 1, treeLeft, mid, left, right);
        int rightSum = findSumRange(2*index + 2, mid+1, treeRight, left, right);

        return leftSum + rightSum;
    }
    
    int sumRange(int left, int right) {
        return findSumRange(0, 0, size-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
