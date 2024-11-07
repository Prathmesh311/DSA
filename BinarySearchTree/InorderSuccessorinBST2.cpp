/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* traverseDown(Node* node){
        if(node->left == NULL && node->right == NULL){
            return node;
        }

        Node* child = node->left ? traverseDown(node->left) : node;
        if(node->val <= child->val){
            return node;
        }
        return child;
    }

    Node* traverseUp(Node* node, int value){
        if(node == NULL){
            return NULL;
        }
        if(node->parent == NULL && node->val >= value){
            return node;
        }

        if(node->val >= value){
            return node;
        }

        return traverseUp(node->parent, value);
    }

    Node* inorderSuccessor(Node* node) {
        Node* minSuccessor;

        if(node->right != NULL){
            minSuccessor =  traverseDown(node->right);
        }else{
            return node->parent;

            return traverseUp(node->parent, node->val);
        }

        return minSuccessor;
    }
};
