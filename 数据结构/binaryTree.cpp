/*
二叉树的增删查改：
二叉树操作主要难点在于删除
*/

//结构体定义

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 //二叉树的删除
TreeNode* deleteNode(TreeNode* root, int key)
{
    if (root == nullptr){
        return nullptr;
    }

    if (root->val > key){
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if (root->left == nullptr && root->right == nullptr){
            return nullptr;
        }
        else if (root->right != nullptr){
            root->val = findMin(root->right);
            root->right = deleteNode(root->right, root->val);
        }
        else if (root->left != nullptr){
            root->val = findMax(root->left);
            root->left = deleteNode(root->left, root->val);
        }
    }

    return root;

}

int findMin(TreeNode* root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->val;    
}

int findMax(TreeNode* root)
{
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->val;    
}

//二叉树插入
TreeNode* insertIntoBST(TreeNode* root, int key)
{
    if (root == nullptr){
        root = newNode(key);
    }
    else if (root->val > key){
        root->left = insertIntoBST(root->left, key);
    }
    else{
        root->right = insertIntoBST(root->right, key);
    }

    return root;
}

TreeNode* newNode(int key)
{
    TreeNode* node = new TreeNode;
    node->left = node->right = nullptr;
    node->val = key;

    return node;
}

//二叉树的查找
TreeNode* findByKey(TreeNode* root, int key)
{
    if (root == nullptr){
        return nullptr;
    }
    else if (root->val > key){
        return findByKey(root->left, key);
    }
    else{
        return findByKey(root->right, key);
    }
}
 

