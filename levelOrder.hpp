#pragma once
#include "Node.hpp"
#include <iostream>
#include <queue>
using namespace std;
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