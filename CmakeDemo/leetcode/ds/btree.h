#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree
{
public:
    Tree() {}
public:
    TreeNode* root = NULL;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL)
        {
            return root;
        }

        if (root == p || root == q)
        {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)
        {
            return root;
        }
        else if (left != NULL)
        {
            return left;
        }
        else if (root != NULL)
        {
            return right;
        }

        return NULL;
    }

    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            
            if (node == NULL)
            {
                while (!q.empty())
                {
                    node = q.front();
                    q.pop();
                    if (node != NULL)
                    {
                        return false;
                    }
                }
                return true;
            }

            q.push(node->left);
            q.push(node->right);

        }

        return true;
    }
};

void test()
{
    vector<int> nums = { 1, 2, 3, 5};
    Tree t;
    t.root = new TreeNode(1);
    t.root->left = new TreeNode(2);
    t.root->right = new TreeNode(3);
    t.root->left->left = new TreeNode(5);
    t.root->right->right = new TreeNode(8);
    Solution solu;
    solu.isCompleteTree(t.root);
}