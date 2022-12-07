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

    int depthFinder(TreeNode* root){
         if(root == NULL){
            return 10000;
        }

        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }

        int left = depthFinder(root->left);
        int right = depthFinder(root->right);

        return min(left, right) + 1;
    } 
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

    
        return depthFinder(root);
        
    }
};
