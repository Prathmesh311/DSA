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
    int valueChecker(TreeNode* root){
        if(root == NULL){
            return -2;      //return -2 if node is null
        }
      

        int left = valueChecker(root->left) == -2? root->val : valueChecker(root->left);  //Avoid checking null nodes
        int right = valueChecker(root->right) == -2? root->val : valueChecker(root->right);

        if(root->val != left || root->val != right){
            return -1;                           //return -1 if tree is not univalued
        }

        return root->val;
    }

    bool isUnivalTree(TreeNode* root) {
         if(root == NULL){
            return true;
        }

        if(valueChecker(root) == -1){
            return false;
        }
        return true;
        
    }
};
