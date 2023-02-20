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
    void inorder(TreeNode *pos)
    {
        if(pos != NULL)
        {
            inorder(pos->left);
            cout<<pos->data<<" ";
            inorder(pos->right);
        }
    }
    void remove(TreeNode *pos, int value)
    {
        if(pos != NULL)
        {
            TreeNode *parent = NULL;
            bool found = false;
            while(pos != NULL)
            {
                if(value == pos->data)
                {
                    found = true;
                    break;
                }
                else if(value < pos->data)
                {
                    parent = pos;
                    pos = pos->left;
                }
                else
                {
                    parent = pos;
                    pos = pos->right;
                }
            }
            if(found)
            {
                if(pos->left != NULL && pos->right == NULL)
                {
                    if(pos == parent->left)
                    {
                        parent->left = pos->left;
                    }
                    else
                    {
                        parent->right = pos->left;
                    }
                    delete pos;
                    cout<<value<<" is deleted successfully\n";
                }
                else if(pos->left == NULL && pos->right != NULL)
                {
                    if(pos == parent->left)
                    {
                        parent->left = pos->right;
                    }
                    else
                    {
                        parent->right = pos->right;
                    }
                    delete pos;
                    cout<<value<<" is deleted successfully\n";
                }
                else
                {
                    cout<<value<<" is not the node that have only child\n";
                }
            }
            else
            {
                cout<<"Value does not exist\n";
            }
        }
        else
        {
            cout<<"No value to delete\n";
        }
    }
};
int main()
{
    BST b;
    b.root = b.insert(b.root, 40);
    b.root = b.insert(b.root, 20);
    b.root = b.insert(b.root, 10);
    b.root = b.insert(b.root, 60);
    b.root = b.insert(b.root, 50);
    b.inorder(b.root);
    cout<<endl;
    b.remove(b.root, 40);
    b.inorder(b.root);
    cout<<endl;
    b.remove(b.root, 20);
    b.inorder(b.root);
    cout<<endl;
    b.remove(b.root, 60);
    b.inorder(b.root);
    cout<<endl;
    b.remove(b.root, 10);
    b.inorder(b.root);
    cout<<endl;
    b.remove(b.root, 70);
    b.inorder(b.root);
    cout<<endl;
}
