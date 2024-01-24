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

    int dfs(TreeNode* root, map<int, int> &occ){
        if(root == NULL){
            return 0;
        }

        if(root->left == NULL && root->right == NULL){
            occ[root->val] += 1;
            int oddCount = 0;

            for(auto p : occ){
                if(p.second % 2 == 1){
                    oddCount++;
                }
                if(oddCount > 1){
                    occ[root->val] -= 1;
                    return 0;
                }
            }
            
            occ[root->val] -= 1;
            return 1;
        }


        occ[root->val] += 1;
        int sum =  dfs(root->left, occ) + dfs(root->right, occ);
        occ[root->val] -= 1;

        return sum;
    }


    int pseudoPalindromicPaths (TreeNode* root) {
        map<int, int> occ;

        return dfs(root, occ);
    }
};
