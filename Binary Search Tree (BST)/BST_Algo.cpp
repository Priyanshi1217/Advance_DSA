// Algo for BST Insertion

#include <iostream>
using namespace std;

struct node{
    int data;
    node*left;
    node*right;
};

// Insert node
node*insert(node*root,int x)
{
    if(root==NULL)
    {
        node*temp=new node;
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    if(x<root->data)
        root->left=insert(root->left,x);
    else if(x>root->data)
        root->right=insert(root->right,x);
    return root;
}

// Search node
bool search(node *root,int x){
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    if(x<root->data)
        return search(root->left,x);
    else
        return search(root->right,x);
}

// Find minimum node 
int findmin(node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

// Find max node
int findmax(node*root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}

//Delete node
node*deletenode(node*root,int x){
    if(root==NULL)
        return root;
    else if(x<root->data)
        root->left=deletenode(root->left,x);
    else if(x>root->data)
        root->right=deletenode(root->right,x);
    else
  // Node having no child
    {
        if (root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
  //  Node having one child
        else if(root->left==NULL)
        {
            node*temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right=NULL)
        {
            node*temp=root->left;
            delete root;
            return temp;
        }


  // Node having two child
        node*temp=new node;
        temp->data=findmin(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
} 


int main() {
    node* root = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }
    cout << "\nEnter element to search: ";
    cin >> x;

    if(search(root, x))
        cout << "Element found" << endl;
    else
        cout << "Element not found" << endl;

    if(root != NULL) {
        cout << "Minimum element: " << findmin(root) << endl;
        cout << "Maximum element: " << findmax(root) << endl;
    }
    cout << "\nEnter element to delete: ";
    cin >> x;

    root = deletenode(root, x);
    cout << "Node deleted successfully!" << endl;
    return 0;
}