// Creation of binary tree
#include <bits/stdc++.h>
using namespace std;
struct node {
    int info;
    node* left;
    node* right;
};
node* create() {
    int x;
    node* p = new node();
    cout << "Enter (-1) for no data: ";
    cin >> x;
    if (x == -1) {
        return NULL;
    }
    p->info = x;
    cout << "Enter left child of " << x << endl;
    p->left = create();
    cout << "Enter right child of " << x << endl;
    p->right = create();
    return p;
}
void preorder(node* p) {
    if (p == NULL)
        return;
    cout << p->info << " ";
    preorder(p->left);
    preorder(p->right);
}
void inorder(node* p) {
    if (p == NULL)
        return;
    inorder(p->left);
    cout << p->info << " ";
    inorder(p->right);
}
void postorder(node* p) {
    if (p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    cout << p->info << " ";
}
int main() {
    node* root = create();
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    return 0;
}
