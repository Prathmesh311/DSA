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
    bool traverse(TreeNode* leftRoot, TreeNode* rightRoot){
        if(leftRoot == NULL && rightRoot == NULL){
            return true;
        }

         if(leftRoot != NULL && rightRoot == NULL || leftRoot == NULL && rightRoot != NULL){
            return false;
        }

        if(leftRoot->val != rightRoot->val){
            return false;
        }

        bool left = traverse(leftRoot->left, rightRoot->right);
        bool right = traverse(rightRoot->left, leftRoot->right);

        if(left && right){
            return true;
        }

        return false;
    }


    bool isSymmetric(TreeNode* root) {
        return traverse(root->left, root->right);
    }
};
