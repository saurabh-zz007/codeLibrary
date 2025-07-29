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
Node* insertInBST(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = new Node(data);
        return newNode;
    }
    if (data < root->data) {
        root->left = insertInBST(root->left, data);
    }
    else {
        root->right = insertInBST(root->right, data);
    }
    return root;
};
void takeInput(Node* & root) {
    int data;
    cin >> data;
    while (data != -1) {
        
        root = insertInBST(root, data);
        cin >> data;
    }


};

int main() {
    
    Node* newNode = NULL;
	cout << "Enter the number of nodes in the tree: ";
    takeInput(newNode);
    levelOrder(newNode);

    return 0;
}