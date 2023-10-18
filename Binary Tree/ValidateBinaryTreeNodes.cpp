class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        queue<int> q;
        vector<int> visited(n, 0);
        set<int> set;

        for(int i=0; i < n; i++){            //inserting all nodes in set
            set.insert(leftChild[i]);
            set.insert(rightChild[i]);
        }

        set.erase(-1);
        if(set.size() == n){
            return false;
        }

        int root = -1;
        for(int i = 0; i < n; i++){
            if(set.find(i) == set.end()){    //finding root node - node is root if it's not present in set as it's node child of anyone
                root = i;
                break;
            }
        }

        q.push(root);
        int node = root;


        while(!q.empty()){                  //using BFS visit all posible nodes
            int size = q.size();

            for(int i=0; i < size; i++){
                node = q.front();
                q.pop();

                if(visited[node] == 1){
                    return false;
                }

                visited[node] = 1;

                int left = leftChild[node];
                int right = rightChild[node];

                if(left != -1){
                    q.push(left);
                }
                if(right != -1){
                    q.push(right);
                }
            }
        }

        for(int i = 0; i < n; i++){              //check if all nodes are being visited. if not visited then tree is not valid
            if(visited[i] == 0){
                return false;
            }
        }

        return true;

    }
};
