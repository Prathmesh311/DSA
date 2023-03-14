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
    int totalSum = 0;
    void findSum(TreeNode* root, int sum){
        if(root == NULL){
            return;
        }
        
        if(root->left == nullptr && root->right == nullptr){
            totalSum += sum + root->val;
            return;
        }

        sum += root->val;
        sum = sum * 10;
    
        findSum(root->left, sum);
        findSum(root->right, sum);

    }

    int sumNumbers(TreeNode* root) {
        findSum(root, 0);
        return totalSum;
    }
};
