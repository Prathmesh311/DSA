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
    void convertToGst(TreeNode* root, int &greater){
        if(root == NULL){
            return;
        }

        convertToGst(root->right, greater);
        root->val = root->val + greater;
        greater = root->val;
        convertToGst(root->left, greater);
    }


    TreeNode* convertBST(TreeNode* root) {
        int greater = 0;
        convertToGst(root, greater);
        return root;
    }
};
