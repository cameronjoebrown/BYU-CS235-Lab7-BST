//
//  BST.cpp
//  Lab7
//
//  Created by Cam on 11/25/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#include "BST.h"

BST :: BST() {
    root = nullptr;
}
BST :: ~BST() {
    clear();
}

NodeInterface* BST :: getRootNode() const {
    return root;
}
bool BST :: add(int val) {
    if(root == nullptr) {
        Node* newRoot = new Node(val);
        root = newRoot;
        return true;
    }
    else if(addHelper(this->root, val)) {
        return true;
    }
    else {
        return false;
    }
}

bool BST :: addHelper(Node* &T, int val) {
    if(T == nullptr) {
        T = new Node(val);
        return true;
    }
    else if(T->data < val) {
        return addHelper(T->rightChild, val);
    }
    else if(T->data > val) {
        return addHelper(T->leftChild, val);
    }
    else {
        return false;
    }
}

bool BST :: remove(int val) {
    return removeHelper(root, val);
}

bool BST :: removeHelper(Node* &T, int val) {
    if(T == nullptr) {
        return false;
    }
    else if(val == T->data) {
        if(T->leftChild == NULL && T->rightChild == NULL) {
            Node* tempNode = T;
            T = NULL;
            delete tempNode;
            return true;
        }
        if (T->rightChild != NULL && T->leftChild == NULL) {
            Node* tempNode = T;
            T = T->rightChild;
            delete tempNode;
            return true;
        }
        if (T->rightChild == NULL && T->leftChild != NULL) {
            Node* tempNode = T;
            T = T->leftChild;
            delete tempNode;
            return true;
        }
        else {
            T->data = traverseTree(T->leftChild);
            return removeHelper(T->leftChild, T->data);
        }
    }
    else {
        T->data = traverseTree(T->leftChild);
        return removeHelper(T->leftChild, T->data);
    }
}

int BST :: traverseTree(Node *T) {
    if (T == nullptr) {
        return -1;
    }
    int currVal = T->data;
    Node* left = T->leftChild;
    if (left != nullptr) {
        int leftVal = traverseTree(left);
        if (leftVal > currVal) {
            currVal = leftVal;
        }
    }
    
    Node* right = T->rightChild;
    if (right != nullptr) {
        int rightVal = traverseTree(right);
        if (rightVal > currVal) {
            currVal = rightVal;
        }
    }
    return currVal;
}
void BST :: clear() {
    clearHelper(root);
}

void clearHelper(Node* T) {
    if(T == nullptr) {
        return;
    }
    else if(T->leftChild != nullptr) {
        clearHelper(T->leftChild);
    }
    else if(T->rightChild != nullptr) {
        clearHelper(T->rightChild);
    }
    else {
        delete T;
        return;
    }
}


