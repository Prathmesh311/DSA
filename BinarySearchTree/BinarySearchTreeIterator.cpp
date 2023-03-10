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
class BSTIterator {
public:
    queue<int> q;
    BSTIterator(TreeNode* root) {
        traversal(root);
    }

    void traversal(TreeNode* root){
        if(root == NULL){
            return;
        }

        traversal(root->left);
        q.push(root->val);
        traversal(root->right);
    }
    
    int next() {
        int nextNum = q.front();
        q.pop();
        return nextNum;
    }
    
    bool hasNext() {
        if(q.empty()){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
