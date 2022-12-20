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
    int longestPath = 0; 
    pair<int,int> UnivaluePathFinder(TreeNode* root){
        if(root == NULL){
            pair<int, int> p;
            p.first = -1001;
            p.second = -1;
            return p;
        }
        if(root->left == nullptr && root->right == nullptr){
            pair<int, int> p;
            p.first = root->val;
            p.second = 1;
            return p;
        }

        pair<int, int> p;
        p.first = root->val;
        p.second = 1;

        pair left = UnivaluePathFinder(root->left);
        pair right = UnivaluePathFinder(root->right);

        if(root->val == left.first && root->val == right.first){
            longestPath = max(longestPath,left.second + right.second+1);
        }

        if(root->val == left.first){
             longestPath = max(longestPath,left.second+1);
             p.second = max(p.second,left.second+1);
        }

        if(root->val == right.first){
             longestPath = max(longestPath,right.second+1);
             p.second = max(p.second,right.second+1);
        }

        return p;

    }

    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr){
            return 0;
        }
       
        pair len = UnivaluePathFinder(root);

        if(longestPath == 1 || longestPath == 0){
            return 0;
        }
        return longestPath-1;
    }
};
