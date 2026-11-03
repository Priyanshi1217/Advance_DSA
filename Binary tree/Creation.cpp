#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

// Count Leaf Nodes (0 children)
int leafnode_count(Node* p) {
    if (p == NULL) {
        return 0;
    }

    if (p->left == NULL && p->right == NULL) {
        return 1;
    }

    return leafnode_count(p->left) +
           leafnode_count(p->right);
}

// Count Internal Nodes (at least 1 child)
int internalnode_count(Node* p) {
    if (p == NULL || (p->left == NULL && p->right == NULL)) {
        return 0;
    }

    return 1 + internalnode_count(p->left) +
               internalnode_count(p->right);
}

// Create Binary Tree
Node* create() {
    int x;

    cout << "Enter data (-1 for No Data): ";
    cin >> x;

    if (x == -1) {
        return NULL;
    }

    Node* newNode = new Node();

    newNode->info = x;

    cout << "Enter left child of " << x << endl;
    newNode->left = create();

    cout << "Enter right child of " << x << endl;
    newNode->right = create();

    return newNode;
}

// Count Total Nodes
int totalcount(Node* p) {
    if (p == NULL) {
        return 0;
    }

    return 1 + totalcount(p->left) +
               totalcount(p->right);
}

// Count Nodes Having Exactly One Child
int leftchild(Node* p) {
    if (p == NULL) {
        return 0;
    }

    int count = 0;

    if ((p->left == NULL && p->right != NULL) ||
        (p->left != NULL && p->right == NULL)) {
        count = 1;
    }

    return count + leftchild(p->left) +
                   leftchild(p->right);
}

// Count Nodes Having Exactly Two Children
int twochild(Node* p) {
    if (p == NULL) {
        return 0;
    }

    int count = 0;

    if (p->left != NULL && p->right != NULL) {
        count = 1;
    }

    return count + twochild(p->left) +
                   twochild(p->right);
}


//calculate height of BT
int height(Node* p){
    if(p==NULL){
        return 0;
    }

    return 1+max(height(p->left),height(p->right));
}

int main() {
    Node* root = NULL;

    cout << "Creating Binary Tree:" << endl;

    root = create();

    cout << "\nNumber of leaf nodes: "
         << leafnode_count(root) << endl;

    cout << "Number of internal nodes: "
         << internalnode_count(root) << endl;

    cout << "Total number of nodes: "
         << totalcount(root) << endl;

    cout << "Number of nodes having one child: "
         << leftchild(root) << endl;

    cout << "Number of nodes having two children: "
         << twochild(root) << endl;


    cout<<"Height of BT "<<height(root)<<endl;

    return 0;
}