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
            cout<<"Duplicate values are not allowed\n";
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
    void search(TreeNode *pos, int value)
    {
        if(pos != NULL)
        {
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
                    pos = pos->left;
                }
                else
                {
                    pos = pos->right;
                }
            }
            if(found)
            {
                cout<<value<<" is present\n";
            }
            else
            {
                cout<<value<<" is not present\n";
            }
        }
        else
        {
            cout<<"No value to search\n";
        }
    }
};
int main()
{
    BST b;
    b.search(b.root, 20);
    b.root = b.insert(b.root, 40);
    b.root = b.insert(b.root, 20);
    b.root = b.insert(b.root, 10);
    b.root = b.insert(b.root, 30);
    b.root = b.insert(b.root, 60);
    b.root = b.insert(b.root, 50);
    b.root = b.insert(b.root, 70);
    b.root = b.insert(b.root, 20);
    b.inorder(b.root);
    cout<<endl;
    b.search(b.root, 20);
    b.search(b.root, 50);
    b.search(b.root, 80);
}
