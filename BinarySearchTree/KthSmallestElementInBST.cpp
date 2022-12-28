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
    void helper(TreeNode* root, vector<int>& preOrder){
        if(root==NULL){
            return;
        }

        helper(root->left, preOrder);
        preOrder.push_back(root->val);
        helper(root->right, preOrder);
    }


    int kthSmallest(TreeNode* root, int k) {
        vector<int> preOrder;
        helper(root, preOrder);

        return preOrder[k-1];
    }
};
