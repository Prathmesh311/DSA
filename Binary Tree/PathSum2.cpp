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

    void findPaths(TreeNode* root, vector<vector<int>>& paths, vector<int>& path, int targetSum){
        if(root == NULL){
            return;
        }

        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            int sum = 0;
            for(int i=0; i < path.size(); i++){
                sum += path[i];
            }
           
            if(sum == targetSum){
                paths.push_back(path);
            }
            path.pop_back();
            return;
        }
        findPaths(root->left, paths, path, targetSum);
        findPaths(root->right, paths, path, targetSum);
        
        path.pop_back();
        return;
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;

        findPaths(root, paths, path, targetSum);
        return paths;
    }
};
