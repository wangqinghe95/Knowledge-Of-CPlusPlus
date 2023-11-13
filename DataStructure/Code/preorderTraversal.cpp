/*
树的先序遍历
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
vector<int> preorderTraversal_iteration(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode* now = st.top();
        st.pop();
        res.push_back(now->val);
        if (now->left != nullptr){
            st.push(now->left);
        }
        if (now->right != nullptr){
            st.push(now->right);
        }
    }
    return res;
}

//递归
vector<int> preorderTraversal_recursion(TreeNode* root)
{
    vector<int> res;
    preorder(root, res);
    return res;
}

void preorder(TreeNode* root, vector<int>& res)
{
    if (root == nullptr){
        return;
    }

    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

