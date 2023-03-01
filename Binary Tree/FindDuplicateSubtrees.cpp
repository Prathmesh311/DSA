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
    string helper(TreeNode* root, map<string, vector<TreeNode*>>& map){
        if(root == NULL){
            return "";
        }

        string s = "("+ helper(root->left, map) + to_string(root->val) + helper(root->right, map) + ")";  //Create string of current path elements

        if(map.find(s) == map.end()){           //add string to map
            vector<TreeNode*> v;
            map.insert(make_pair(s,  v));
        }

        map[s].push_back(root);                 //add starting treenode to map for specific string
        
        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        map<string, vector<TreeNode*>> map;

        helper(root, map);

        for(pair p : map){                        //if for any specific path more than 1 starting tree nodes present that means duplicate substree is present
            if(p.second.size() > 1){
                ans.push_back(p.second[0]);
            }
        }
        return ans;
    }
};
