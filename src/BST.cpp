#include <iostream>
#include <vector>
#include <queue>
#include "../include/Node.hpp"
#include "../include/levelOrder.hpp"

using namespace std;

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