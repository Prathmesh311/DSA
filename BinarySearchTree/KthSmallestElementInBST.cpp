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
    void helper(TreeNode* root, vector<int>& preOrder){   //storing method
        if(root==NULL){
            return;
        }

        helper(root->left, preOrder);
        preOrder.push_back(root->val);
        helper(root->right, preOrder);
    }
    
    int ans = -1;
    void helperRec(TreeNode* root, int& k){              //without storing nodes
        if(root==NULL){
            return;
        }

        helperRec(root->left, k);
        k--;
        if(k == 0){
            ans = root->val;
        }
        helperRec(root->right, k);
    }


    int kthSmallest(TreeNode* root, int k) {
        vector<int> preOrder;
        helper(root, preOrder);
        return preOrder[k-1];
        
        helper(root, k);
        return ans;
    }
};
