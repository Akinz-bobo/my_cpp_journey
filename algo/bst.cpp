#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{

public:
    Node *root;
    BinarySearchTree()
    {
        root = nullptr;
    };
    bool insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode; // first item
            return true;
        }
        Node *temp = root; // to keep track of the node
        while (true)
        {
            if (newNode->value == temp->value)
                return false; // node already exist;
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            };
        }
    }
    bool contains(int value)
    {
        // if (root == nullptr)
        // return false;
        Node *temp = root;
        while (temp)
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
}

;

int main()
{
    BinarySearchTree *myBST = new BinarySearchTree();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);
    myBST->insert(27);

    cout << "Contains 27: " << myBST->contains(27) << endl;
    cout << "Contains 17: " << myBST->contains(17) << endl;

    cout << myBST->root->right->value << endl;
}