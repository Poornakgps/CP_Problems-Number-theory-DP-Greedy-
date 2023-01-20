#include <bits/stdc++.h>

#define ll long long

using namespace std;

typedef struct treenode {
    int info;
    struct treenode *left,
        *right;
}treenode;
 

treenode* create()
{
    int data;
    treenode* tree;

    tree = new treenode;
 
    cout << "\nEnter data to be inserted "
         << "or type -1 for no insertion : ";

    cin >> data;

    if (data == -1)
        return 0;

    tree->info = data;
 
    cout << "Enter left child of : "
         << data;
    tree->left = create();
 
    cout << "Enter right child of : "
         << data;
    tree->right = create();
 
    return tree;
}

int ans(treenode *root){

    if (root==NULL) return 0;

    int lh=ans(root->left); 
    if(lh==-1) return -1;

    int rh=ans(root->right);
    if(rh==-1) return -1;

    if(abs(rh-lh)>1) return -1;
    return max(rh,lh)+1;
}

ll maxdepth(treenode *root){
    if(root==NULL) return 0;
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    return 1+max(rh,lh);
}
bool avltree(treenode *root){
    return ans(root)+1;
}

int height(treenode *root, int &d){

    if(root==NULL) return 0;

    int lh= height(root->left, d);
    int rh= height(root->right,d);
    d=max(d, lh+rh);
    return 1+max(lh,rh);
}

int diameter(treenode *root){
    if(root==NULL) return 0;

    int d=0;
    height(root,d);
    return d;
}


int main(){

    struct treenode* root = NULL;

    root = create();

    cout<<avltree(root)<<endl;
    cout<<diameter(root)<<endl;
    return 0;
}