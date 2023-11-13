/*
树的后序序遍历--迭代和递归
*/

#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//迭代
vector<int> postorderTraversal_iterator(TreeNode* root) 
{
    vector<int> res;
    if (root == nullptr){
        return res;
    }

    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;

    stk1.push(root);
    while (!stk1.empty()){
        TreeNode* now = stk1.top();
        stk1.pop();
        stk2.push(now);

        if (now->left != nullptr){
            stk1.push(now->left);
        }
        if (now->right != nullptr){
            stk2.push(now->right);
        }
    }

    while (!stk2.empty()){
        TreeNode* now = stk2.top();
        stk2.pop();
        res.push_back(now->val);
    }

    return res;
}

//递归
vector<int> postorderTraversal_recursion(TreeNode* root)
{
    vector<int> res;
    postorder(root, res);
    return res;
}

void postorder(TreeNode* root, vector<int> &res)
{
    if (root == nullptr){
        return ;
    }
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}
