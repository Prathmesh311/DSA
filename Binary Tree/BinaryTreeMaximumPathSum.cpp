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
    int maxSum;
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        
        traversal(root);
        
        return maxSum;
    }
    
    int traversal(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int left = max(0, traversal(root->left));
        int right = max(0, traversal(root->right));
        
        maxSum = max(maxSum, left+ right+ root->val);
        
        return max(left, right) + root->val;
    }
};
