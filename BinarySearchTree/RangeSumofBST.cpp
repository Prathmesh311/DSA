/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void iterator(TreeNode* root, int low, int high, int& rangeSum){
        if(root==NULL){
            return;
        }

        if(low <= root->val && root->val <= high){
            rangeSum = rangeSum + root->val;
            iterator(root->left, low, high, rangeSum);
            iterator(root->right, low, high, rangeSum);
        }else if(low >= root->val){
            iterator(root->right, low, high, rangeSum);
        }else if(high <= root->val){
            iterator(root->left, low, high, rangeSum);
        }
        

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int rangeSum = 0;
        iterator(root, low, high, rangeSum);
        return rangeSum;
        
    }
};
