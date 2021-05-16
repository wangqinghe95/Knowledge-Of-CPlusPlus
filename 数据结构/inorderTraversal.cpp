/*
树的中序遍历--迭代和递归
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
vector<int> inorderTraversal_iteration(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr){
        return res;
    }

    TreeNode* node = root;

    stack<TreeNode*> st;
    while(node != nullptr || !st.empty()){
        while(node != nullptr){
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();
        res.push_back(root->val);
        node = node->right;
    }

    return res;
}

//递归
vector<int> inorderTraversal_recursion(TreeNode* root)
{
    vector<int> res;
    inorder(root, res);
    return res;
}

void inorder(TreeNode* root, vector<int>& res)
{
    if (root == nullptr){
        return ;
    }

    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}