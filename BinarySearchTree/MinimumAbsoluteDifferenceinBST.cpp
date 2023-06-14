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
    void traverse(TreeNode* root, vector<int>& nodes){
        if(root == NULL){
            return;
        }

        nodes.push_back(root->val);

        traverse(root->left, nodes);
        traverse(root->right, nodes);
    }
  
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;

        traverse(root, nodes);

        sort(nodes.begin(), nodes.end());
        int minDiff = INT_MAX;

        for(int i=nodes.size()-1; i >0; i--){
            minDiff = min(minDiff, nodes[i] - nodes[i-1]);
        }
        return minDiff;
    }
};
