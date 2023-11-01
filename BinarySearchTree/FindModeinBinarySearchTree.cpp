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

    void mode(TreeNode* root, map<int, int> &map){
        if(root == NULL){
            return;
        }

        int value = root->val;
        if(map.find(value) == map.end()){
            map[value] = 1;
        }
        else{
            map[value] += 1;
        }
        mode(root->left, map);
        mode(root->right, map);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        map<int, int> map;
        mode(root, map);

        int maxOcc = 0;
        for(auto pair: map){
            if(pair.second > maxOcc){
                ans.clear();
                ans.push_back(pair.first);
                maxOcc = pair.second;
            }else if(pair.second == maxOcc){
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};
