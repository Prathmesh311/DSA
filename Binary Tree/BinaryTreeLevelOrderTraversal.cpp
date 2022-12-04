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

    void traversal(TreeNode* root, vector<vector<int>> &order, int level){
        if(root == nullptr){
            return;
        }
       
        if(order.size() <= level){
            order.push_back(vector<int>());
        }

        order[level].push_back(root->val);  //Storing node data in levels

        if(root->left != nullptr){
            traversal(root->left, order, level+1);
        }
        if(root->right != nullptr){
            traversal(root->right, order, level+1);
        }
        
        
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
       
        traversal(root, order, 0);
        return order;
    }
};
