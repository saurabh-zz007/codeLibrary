
#pragma once
#include <iostream>
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


