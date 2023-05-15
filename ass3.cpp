/* Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every node
(Mirror Image).
v. Search a value   */
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
    node()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
};
class Tree
{
public:
    int nodes = 0;
    node *insert(node *root, int data)
    {
        if (root == nullptr)
        {
            root = new node(data);
        }
        else if (root->data < data)
        {
            root->right = insert(root->right, data);
        }
        else
        {
            root->left = insert(root->left, data);
        }
        return root;
        nodes++;
    }

    node *inorder(node *root)
    {
        if (root != nullptr)
        {
            root->left = inorder(root->left);
            cout << root->data << " ";
            root->right = inorder(root->right);
        }
        return root;
    }
    node *postorder(node *root)
    {
        if (root != nullptr)
        {
            root->left = postorder(root->left);
            root->right = postorder(root->right);
            cout << root->data << " ";
        }
        return root;
    }
    node *preorder(node *root)
    {
        if (root != nullptr)
        {
            cout << root->data << " ";
            root->left = preorder(root->left);
            root->right = preorder(root->right);
        }
        return root;
    }
    void display(node *root)
    {
        cout << "in-order: ";
        inorder(root);
        cout << endl;
        cout << "post-order: ";
        postorder(root);
        cout << endl;
        cout << "pre-order: ";
        preorder(root);
        cout << endl;
    }

    int minimun(node *root)
    {
        if(root==nullptr)
        {
            return -1;
        }
        if(root->left!=nullptr)
        {
            root = root->left;
        }
        return root->data;
    }

    bool search(node *root, int val)
    {
        if(root==nullptr)
        {
            return false;
        }
        if(root->data == val)
        {
            return true;
        }
        else if (root->data > val)
        {
            return search(root->left, val);
        }else if(root->data<val)
        {
            return search(root->right, val);
        }
        return false;
    }
};

int main()
{
    node *root = nullptr;
    int no, ch, ch1,element;
    Tree ob;
    cout << "\nHow many nodes you want to insert:  ";
    cin >> no;
    for (int i = 0; i < no; i++)
    {
        int n;
        cout << "\nEnter data: ";
        cin >> n;
        root = ob.insert(root, n);
    }
    ob.display(root);

    do
    {
        cout << "Do you want to insert a new node? (1:yes, 2:no)";
        cin >> ch;
        if (ch == 1)
        {
            int value;
            cout << "\nEnter the value: ";
            cin >> value;
            ob.insert(root, value);
            cout << "\nNew tree : ";
            ob.display(root);
        }
        else if (ch==0)
        {
            break;
        }
    } while (ch == 1);
    int ans = ob.minimun(root);
    cout << "\nThe minimum value is : " << ans;
    cout<<"\nDo you want to search for any value?  (1:yes, 2:no)";
    cin>>ch1;
    cout<<"\nEnter element: ";
    cin>>element;
    if(ob.search(root, element))
    {
        cout<<"\nElement is present..";
    }
    else{cout<<"\nElement is not present..";}
    return 0;
}