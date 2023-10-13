/*
已知先序中序序列、中序后序序列，建立二叉树
*/
#include<vector>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//先序中序建树
TreeNode* createTree(vector<int> &pre, int preL, int preR, vector<int> &in, int inL, int inR){
    if (preL > preR){
        return nullptr;
    }

    TreeNode* root = new TreeNode;
    root->val = pre[preL];

    int k = inL;
    for (; k <= inR; k++){
        if (pre[preL] == in[k]){
            break;
        }
    }

    int numLeft = k - inL;
    root->left = createTree(pre, preL+1, preL+numLeft, in, inL, inL+numLeft-1);
    root->right = createTree(pre, preL+numLeft+1, preR, in, inL+numLeft+1, inR);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return createTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size() - 1);
}

//中序后序建树
TreeNode* createTree(vector<int>&in, int inL, int inR, vector<int>& post, int postL, int postR)
{
    if (postL > postR){
        return nullptr;
    }
    TreeNode* root = new TreeNode;
    root->val = post[postR];

    int k = inL;
    for (; k <= inR; k++){
        if (post[postR] == in[k]){
            break;
        }
    }

    int numLeft = k - inL;
    root->left = createTree(in, inL, inL+numLeft, post, postL, postL+numLeft-1);
    root->right = createTree(in, k+1, inR, post, postL+numLeft, postR-1);
    
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return createTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}