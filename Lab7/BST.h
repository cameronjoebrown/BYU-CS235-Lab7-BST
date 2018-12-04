//
//  BST.h
//  Lab7
//
//  Created by Cam on 11/25/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include <stdio.h>
#include "BSTInterface.h"
#include "Node.h"

using namespace std;

class BST : public BSTInterface {
public:
    BST();
    ~BST();
    NodeInterface* getRootNode() const;
    bool add(int val);
    bool addHelper(Node* &T, int val);
    bool remove(int val);
    bool removeHelper(Node* &T, int val);
    void clear();
    void clearHelper(Node* T);
    int traverseTree(Node* T);
    
private:
    Node* root;
};

#endif /* BST_h */
