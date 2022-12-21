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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }

        if(val == root->val){
            return root;
        }
        else if(val <= root->val){
            root->left = searchBST(root->left, val);
            if(root->left != NULL){
                return root->left;
            }else{
                return NULL;
            }
        }
        else{
            root->right = searchBST(root->right, val);
            if(root->right != NULL){
                return root->right;
            }else{
                return NULL;
            }
        }

        return root;
    }
};
