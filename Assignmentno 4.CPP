#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    bool threaded;

    Node(int val) : value(val), left(NULL), right(NULL), threaded(false) {}
};

Node* preorder_successor(Node* node) {
    if (node->left != NULL)
        return node->left;

    while (node != NULL && node->threaded)
        node = node->right;

    return node != NULL ? node->right : NULL;
}

void preorder_threading(Node* node, Node*& prev) {
    if (node == NULL)
        return;

    if (prev != NULL) {
        prev->right = node;
        prev->threaded = true;
    }

    if (node->left != NULL)
        preorder_threading(node->left, prev);

    if (node->right != NULL && !node->threaded)
        preorder_threading(node->right, prev);

    prev = node;
}

Node* constructBinaryTree(const vector<int>& values) {
    if (values.empty())
        return NULL;

    Node* root = new Node(values[0]);
    Node* curr = root;

    for (size_t i = 1; i < values.size(); ++i) {
        Node* newNode = new Node(values[i]);
        curr->left = newNode;
        curr = newNode;
    }

    return root;
}

void displayPreorder(Node* node) {
    cout << "Complete Preorder Traversal of Threaded Binary Tree: ";
    while (node != NULL) {
        cout << node->value << " ";

        if (!node->threaded)
            node = node->left;
        else
            node = node->right;
    }
    cout << endl;
}

int main() {
    cout << "Binary Tree to Threaded Binary Tree Converter" << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Enter the values of the nodes (enter -1 to represent null):" << endl;
    vector<int> values;
    int val;
    while (cin >> val && val != -1) {
        values.push_back(val);
    }

    Node* root = constructBinaryTree(values);

    Node* prev = NULL;
    preorder_threading(root, prev);

    displayPreorder(root);

    return 0;
}

