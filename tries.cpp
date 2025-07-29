#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};
void levelOrder(Node*& root) {
    queue<Node*> q;
    if (root == NULL) return;

    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        if (q.front() == NULL) {
            cout << endl;
            q.pop();
            if (q.empty())
                return;
            q.push(NULL);
        }
        Node* temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);

        cout << temp->data << " ";
    }

};
static int idx = -1;
Node* buildTree(vector<int> preOrder) {
    idx++;
    if (idx >= preOrder.size() || preOrder[idx] == -1)
        return NULL;

    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;

};