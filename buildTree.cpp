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

int main() {
    vector<int> v = {
1, 2, 4, 8, 16, -1, -1, 17, -1, -1, 9, 18, -1, -1, 19, -1, -1,
5, 10, 20, -1, -1, 21, -1, -1, 11, 22, -1, -1, 23, -1, -1,
3, 6, 12, 24, -1, -1, 25, -1, -1, 13, 26, -1, -1, 27, -1, -1,
7, 14, 28, -1, -1, 29, -1, -1, 15, 30, -1, -1, 31, -1, -1
    };
    Node* newNode = buildTree(v);
    levelOrder(newNode);

    return 0;
}