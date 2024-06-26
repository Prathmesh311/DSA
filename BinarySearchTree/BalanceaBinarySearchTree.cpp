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
    void traverse(TreeNode* root, vector<int> &nodes){
        if(root == NULL){
            return;
        }

        traverse(root->left, nodes);
        nodes.push_back(root->val);
        traverse(root->right, nodes);
    }
    
    TreeNode* createBalanceBST(vector<int> &nodes, int left, int right){
        if(left > right){
            return NULL;
        }
        
        int mid = left + (right - left)/2;

        TreeNode* root = new TreeNode(nodes[mid]);

        root->left = createBalanceBST(nodes, left, mid - 1);
        root->right = createBalanceBST(nodes, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;

        traverse(root, nodes);

        sort(nodes.begin(), nodes.end());

        return createBalanceBST(nodes, 0, nodes.size()-1);
    }
};
