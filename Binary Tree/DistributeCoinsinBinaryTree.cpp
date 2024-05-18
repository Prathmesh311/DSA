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
    int traverse(TreeNode* root, int& moves){
        if(root == NULL){
            return 0;
        }

        int left = traverse(root->left, moves);
        int right = traverse(root->right, moves);

        int currMoves = root->val - 1 + left + right;
        moves += abs(currMoves);
        
        return currMoves;
    }


    int distributeCoins(TreeNode* root) {
        int moves = 0;
        traverse(root, moves);
        return moves;
    }
};
