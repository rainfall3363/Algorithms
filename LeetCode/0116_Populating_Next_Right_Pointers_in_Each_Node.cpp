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
    Node* connect(Node* root) {
        queue<Node*> que;
        que.push(root);
        int level = 1;
        int cnt = 0;
        
        if (root == NULL) {
            return root;    
        }
        while (!que.empty()) {
            Node* current = que.front();
            cnt++;
            if (current->left != nullptr && current->right != nullptr) {
                que.push(current->left);
                que.push(current->right);      
            }
            que.pop();
            if (cnt == level) {
                current->next = NULL;
                level *= 2;
                cnt = 0;
            }
            else {
                current->next = que.front();
            }
        }
        
        return root;
    }
};
