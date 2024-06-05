
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    int ith, rth;
    node *left, *right;
};

class TBT
{
private:
    node *dummy;
    node *New, *root, *temp, *parent;

public:
    TBT()
    {
        root = NULL;
    }

    void create();
    void insert(node *current, node *New);
    void Print();
    void inorder(node *temp);
    void preorder(node *temp);
};

void TBT::create()
{
    New = new node;
    New->left = NULL;
    New->right = NULL;
    New->ith = 0;
    New->rth = 0;
    cout << "\nEnter The Element: ";
    cin >> New->data;

    if (root == NULL)
    {
        root = New;
        dummy = new node;
        dummy->data = -999;
        dummy->left = root;
        root->left = dummy;
        root->right = dummy;
    }
    else
    {
        insert(root, New);
    }
}

void TBT::insert(node *current, node *New)//////////recursive
{
    if (New->data < current->data)
    {
        if (current->ith == 0)
        {
            New->left = current->left;
            New->right = current;
            current->left = New;
            current->ith = 1;
        }
        else
        {
            insert(current->left, New);
        }
    }
    else if (New->data > current->data)
    {
        if (current->rth == 0)
        {
            New->right = current->right;
            New->left = current;
            current->rth = 1;
            current->right = New;
        }
        else
        {
            insert(current->right, New);
        }
    }
}

void TBT:: Print()
{
    if (root == NULL)
    {
        cout << "Tree Is Not Created";
    }
    else
    {
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << "\nPreorder Traversal: ";
        preorder(root);
    }
}

void TBT::inorder(node *temp)
{
    while (temp != dummy)
    {
        while (temp->ith == 1)
        {
            temp = temp->left;
        }
        cout << temp->data << " ";
        while (temp->rth == 0)
        {
            temp = temp->right;
            if (temp == dummy)
            {
                return;
            }
            cout << temp->data << " ";
        }
        temp = temp->right;
    }
}

void TBT::preorder(node *temp)
{
    int flag = 0;

    while (temp != dummy)
    {
        if (flag == 0)
        {
            cout << temp->data << " ";
        }
        if (temp->ith == 1 && flag == 0)
        {
            temp = temp->left;
        }
        else
        {
            while (1)
            {
                if (temp->rth == 1)
                {
                    flag = 0;
                    temp = temp->right;
                    break;
                }
                else
                {
                    if (temp != dummy)
                    {
                        flag = 1;
                        temp = temp->right;
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    int choice;
    char ans = 'N';
    TBT obj;

    do
    {
        cout << "\n\t Program For Threaded Binary Tree";
        cout << "\n1. Create \n2. Print (Inorder & Preorder traversal)\n3. Exit \nENTER CHOICE: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            do
            {
                obj.create();
                cout << "\nDo you want to enter more nodes? (y/n): ";
                cin >> ans;
            } while (ans == 'y');
            break;

        case 2:
            obj.Print();
            break;

        case 3:
            cout << "Application exit";
            break;

        default:
            cout << "Invalid choice";
            break;
        }
    } while (choice != 3);

    return 0;
}
