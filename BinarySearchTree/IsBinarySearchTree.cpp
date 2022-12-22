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
    bool isBST(TreeNode* root, long minValue, long maxValue){
        if(root==NULL){
            return true;
        }

        long value = root->val;
       
        if(value > minValue && value < maxValue && 
            isBST(root->left, minValue, value) && 
            isBST(root->right, value, maxValue))
        {
            return true;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
       
        return isBST(root, -2147483649, 2147483649);
        
    }
};
