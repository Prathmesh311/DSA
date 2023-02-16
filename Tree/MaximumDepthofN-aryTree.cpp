/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int traversal(Node* root){
        if(root == NULL){
            return 0;
        }

        int depth = 0;

        for(Node* child : root->children){
            int currDepth = traversal(child) + 1;
            depth = max(depth, currDepth);
        }

        return depth;
    }
    
    int maxDepth(Node* root) {
        if(root == NULL){
            return 0;
        }
        return traversal(root) + 1;
    }
};
