/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node* node, map<Node*, Node*>& map){
        if(node == NULL){
            return node;
        }
       
        if(map.find(node) != map.end()){  //If copy node contains return it
            return map[node];
        }
        
        Node* copy = new Node(node->val); //create copy node
        map[node] = copy;

        for(Node* nbr: node->neighbors){  //calling clone on neighboring nodes
            Node* newNbr = clone(nbr, map);
            copy->neighbors.push_back(newNbr);
        }
        
        return copy;
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> map;
        return clone(node, map);
    }
};
