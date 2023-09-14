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
    void findGoodNodes(TreeNode* root, int maxNode, int &countGoodNodes){
        if(root == NULL){
            return;
        }

        if(root->val >= maxNode){
            maxNode = root->val;
            countGoodNodes++;
        }

        findGoodNodes(root->left, maxNode, countGoodNodes);
        findGoodNodes(root->right, maxNode, countGoodNodes);
    }
    int goodNodes(TreeNode* root) {
        int maxNode = root->val;
        int countGoodNodes = 0;

        findGoodNodes(root, maxNode, countGoodNodes);
        return countGoodNodes;
    }
};
