#include<iostream>
#include<stdlib.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }
    TreeNode* insert(TreeNode *pos, int value)
    {
        if(pos == NULL)
        {
            TreeNode *new_node = new TreeNode(value);
            return new_node;
        }
        else if(value == pos->data)
        {
            cout<<"\nDuplicate values are not allowed\n";
            return pos;
        }
        else if(value < pos->data)
        {
            pos->left = insert(pos->left, value);
        }
        else
        {
            pos->right = insert(pos->right, value);
        }
    }
    void preorder(TreeNode *pos)
    {
        if(pos != NULL)
        {
            cout<<pos->data<<" ";
            preorder(pos->left);
            preorder(pos->right);
        }
    }
};
int main()
{
    BST b;
    b.root = b.insert(b.root, 40);
    b.root = b.insert(b.root, 20);
    b.root = b.insert(b.root, 10);
    b.root = b.insert(b.root, 30);
    b.root = b.insert(b.root, 60);
    b.root = b.insert(b.root, 50);
    b.root = b.insert(b.root, 70);
    b.preorder(b.root);
}
