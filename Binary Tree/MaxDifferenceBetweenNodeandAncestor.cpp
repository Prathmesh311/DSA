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

    void diffFinder(TreeNode* root, vector<int>& ancestor, int& maxDiff){
        if(root == NULL){
            return;
        }

        if(ancestor.size() > 0){     //checking if ancestor is present 
            for(int i=0; i < ancestor.size(); i++){
                maxDiff = max(abs(ancestor[i] - root->val), maxDiff);   //assigning maxDiff
            }
        }

        ancestor.push_back(root->val);       //pushing ancestor 

        diffFinder(root->left, ancestor, maxDiff);
        diffFinder(root->right, ancestor, maxDiff);

        ancestor.pop_back();               //poping ancestor
    }

    int maxAncestorDiff(TreeNode* root) {
        vector<int> ancestor;
        int maxDiff = 0;

        diffFinder(root, ancestor, maxDiff);

        return maxDiff;
        
    }
};
