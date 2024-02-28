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
    void traverse(TreeNode* root, int &bottomLeftNode, int &maxDepth, int currDepth){
        if(root == NULL){
            return;
        }

        if(currDepth > maxDepth){
            maxDepth = currDepth;
            bottomLeftNode = root->val;
        }

        traverse(root->left, bottomLeftNode, maxDepth, currDepth+1);
        traverse(root->right, bottomLeftNode, maxDepth, currDepth+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        int bottomLeftNode;
        int maxDepth = -1;
        int currDepth = 0;
        
        traverse(root, bottomLeftNode, maxDepth, currDepth);

        return bottomLeftNode;
    }
};
