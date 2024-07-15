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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map;
        set<int> childs;
        
        for(vector<int> v : descriptions){
            TreeNode* parent;
            TreeNode* child;

            if(map.find(v[0]) == map.end()){
                parent = new TreeNode(v[0]);
                childs.insert(v[0]);
                map[v[0]] = parent;
            }else{
                parent = map[v[0]];
            }

            if(map.find(v[1]) == map.end()){
                child = new TreeNode(v[1]);
                childs.insert(v[1]);
                map[v[1]] = child;
            }else{
                child = map[v[1]];
            }

            if(v[2] == 1){
                parent->left = child;
            }else{
                parent->right = child;
            }

            childs.erase(v[1]);
        }

        for(int root : childs){
            return map[root];
        }

        return NULL;
    }
};
