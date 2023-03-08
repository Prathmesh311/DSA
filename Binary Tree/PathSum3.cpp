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
    int totalPathSums = 0;
    void findTargetSum(TreeNode* root, int targetSum, int currSum){
        if(root == NULL){
            return;
        }
           
        if(targetSum == currSum + root->val){
            totalPathSums++;
        }

        findTargetSum(root->left, targetSum, currSum + root->val);   //Option 1: select current Node
        findTargetSum(root->left, targetSum, 0);                     //Option 2: ignore current Node

        findTargetSum(root->right, targetSum, currSum + root->val);
        findTargetSum(root->right, targetSum, 0);
    }

    int ans = 0;
    void DFS(TreeNode* root, int targetSum){
        if(root == NULL){
            return;
        }

        if(targetSum == root->val){
            ans++;
        }
        if(targetSum - root->val < -10000001){   //TO tackle int overflow
            return;
        }

        DFS(root->left, targetSum - root->val);
        DFS(root->right, targetSum - root->val);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            DFS(root, targetSum);              //Doing DFS on each node
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }

        return ans;

        findTargetSum(root, targetSum, 0);     //Good time savinf approach but unable to pass Degenerate Tree test cases
        return totalPathSums;
        
    }
};
