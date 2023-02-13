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
    void traversal(Node* root, vector<int> &order){
        if(root == NULL){
            return;
        }

        for(Node* child: root->children){
            traversal(child, order);
        }
        
        order.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> order;

        traversal(root, order);

        return order;
    }
};
