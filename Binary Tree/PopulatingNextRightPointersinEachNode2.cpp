/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void traverse(Node* root, unordered_map<int, Node*> &map, int depth){
        if(root == NULL){
            return;
        }

        Node* currNode = root;
        currNode->next = map[depth];
        map[depth] = currNode;

        traverse(root->right, map, depth+1);
        traverse(root->left, map, depth+1);
    }

    Node* connect(Node* root) {
        unordered_map<int, Node*> map;

        traverse(root, map, 0);

        return root;
    }
};
