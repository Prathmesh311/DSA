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
    int maxLevel = -1;
    void treeTraversal(TreeNode* root, vector<int>& rightView, int level){
        if(root == NULL){
            return;
        }

        if(level > maxLevel){
            rightView.push_back(root->val);
            maxLevel = level;
        }

        treeTraversal(root->right, rightView, level+1);
        treeTraversal(root->left, rightView, level+1);
        return;

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        treeTraversal(root, rightView, 0);
        return rightView;
    }
};
