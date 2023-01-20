
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
 

void inorder(treenode* root)
{

    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->info << "  ";
    inorder(root->right);
}

void post_order(treenode *root)
{
    if(root!=NULL)
    {      
        post_order(root->left);
        post_order(root->right);
        cout<<root->info<<" ";
    }
}

void pre_order(treenode *root)
{
    if(root!=NULL)
    {
        cout<<root->info<<" ";
        pre_order(root->left);
        pre_order(root->right);
    }
}

void LevelOrder(treenode* root)
{
    if (root == NULL)
        return;
 
    queue<treenode*> q;
 
    q.push(root);
 
    while (q.empty() == false) {
        treenode* node = q.front();
        cout << node->info << " ";
        q.pop();

        if (node->left != NULL)
            q.push(node->left);
 
        if (node->right != NULL)
            q.push(node->right);
    }
}

void inorder_iterative(treenode *root){

    stack<treenode *> s;
    s.push(root);
    //queue<ll> que;
    treenode* node=root;
    while(1){
        //preOrder.push_back(topNode -> data);
        if(node!=NULL){
            s.push(node);
            
            node=node->left;
        }
        else{
            
            if(s.empty()){
                break;
            }
            node=s.top();
            cout<<node->info<<" ";
            s.pop();
            node=node->right;
        }
    }
    cout<<endl;
}

int main()
{

    struct treenode* root = NULL;

    root = create();
    cout<<"Recursive printing\n";
    cout<<"\ninorder DFS: ";
    inorder(root);
    cout<<endl;
    cout<<"\npostorder DFS: ";
    post_order(root);
    cout<<endl;
    cout<<"\npreorder DFS: ";
    pre_order(root);
    cout<<endl;

    cout<<"\nTraversal printing\n";
    cout<<"\nLevel order: ";
    LevelOrder(root);

    cout<<"\ninorder iterative: ";
    inorder_iterative(root);

    return 0;
}