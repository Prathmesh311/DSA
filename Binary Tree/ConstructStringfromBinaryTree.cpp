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
    void createString(TreeNode* root, string &str){
        if(root == NULL){
            return;
        }
       
        str +=  to_string(root->val);
        if(root->left != NULL){
            str += "(";
            createString(root->left, str);
        }
        else if(root->left == NULL && root->right != NULL){
            str += "()";
        }
        
        if(root->right != NULL){
            str += "(";
            createString(root->right, str);
        }

        str += ')';

    }
    string tree2str(TreeNode* root) {
        string ans = "";
        createString(root, ans);
        return ans.erase(ans.size()-1);
    }
};
