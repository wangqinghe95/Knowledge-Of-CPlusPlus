/*
平衡二叉树的插入
*/
#include<cstdio>

struct Node{
    int v;
    int height;
    Node* lchild, *rchild;
};

Node* newNode(int v);
void insert(Node* &root, int v);
void updateHeight(Node* root);
int getHeight(Node* root);
int getBalanceFactor(Node* root);
void R(Node* &root);
void L(Node* &root);

int main(){
    int v;
    int n;
    scanf("%d", &n);
    Node *root;
    for (int i = 0; i < n; ++i){
        scanf("%d", &v);
        insert(root, v);
    }
}

void insert(Node* &root, int v)
{
    if (root == nullptr){
        root = newNode(v);
        return;
    }
    if (root->v > v){
        insert(root->lchild,v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2){
            if (getBalanceFactor(root->lchild) == 1){
                R(root);
            }
            else if (getBalanceFactor(root->lchild) == -1){
                L(root->lchild);
                R(root);
            }
        }
    }
    else if (root->v < v){
        insert(root->rchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2){
            if (getBalanceFactor(root->rchild) ==  -1){
                L(root);
            }
            else if (getBalanceFactor(root->rchild) == 1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

Node* newNode(int v)
{
    Node* root = new Node;
    root->v = v;
    root->height = 1;
    root->lchild = root->rchild = nullptr;
    return root;
}

void updateHeight(Node* root)
{
    int lHeight = getHeight(root->lchild);
    int rHeight = getHeight(root->rchild);
    root->height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

int getHeight(Node* root)
{
    if (root == nullptr){
        return 0;
    }
    else{
        return root->height;
    }
}

int getBalanceFactor(Node* root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void R(Node* &root)
{
    Node* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void L(Node* &root)
{
    Node* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}