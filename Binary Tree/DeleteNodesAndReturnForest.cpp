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
    TreeNode* findAndDelete(TreeNode* root, vector<TreeNode*> &forests, int target){
        if(root == NULL){
            return NULL;
        }

        if(root->val == target){
            if(root->left != NULL){
                forests.push_back(root->left);
            }

            if(root->right != NULL){
                forests.push_back(root->right);
            }
            return NULL;
        }
        
        root->left = findAndDelete(root->left, forests, target);
        root->right = findAndDelete(root->right, forests, target);

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forests;

        sort(to_delete.begin(), to_delete.end());

        if(root->val != to_delete[0]){
            forests.push_back(root);
        }

        for(int i = to_delete.size()-1; i >= 0; i--){
            findAndDelete(root, forests, to_delete[i]);
        }

        return forests;
    }
};
