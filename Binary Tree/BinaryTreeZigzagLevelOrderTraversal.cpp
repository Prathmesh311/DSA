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
    void traversal(vector<vector<int>> &order, TreeNode* root, int level){
        if(root == NULL){
            return;
        }
        
        if(level > maxLevel){
            maxLevel = level;
            vector<int> newVector;
            newVector.push_back(root->val);
            order.push_back(newVector);
        }
        else if(level % 2 != 0){
            order[level].insert(order[level].begin(), root->val);
        }else{
            order[level].push_back(root->val);
        }

        traversal(order, root->left, level+1);
        traversal(order, root->right, level+1);

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> order;
        traversal(order, root, 0);
        return order;
    }
};
