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

int algo(treenode *root, int &ans){

    if(root==NULL) return 0;

    int maxL=max(0,algo(root->left, ans));

    int maxR=max(0, algo(root->right, ans));

    ans=max(ans, maxL + maxR + root->info );

    return max(maxL,maxR)+root->info;
}

int maxpathSum(treenode *root){


    int ans=INT_MIN;
    algo(root,ans);
    return  ans;
}

int main(){
    treenode *root=NULL;

    root=create();

    cout<<maxpathSum(root)<<endl;
}