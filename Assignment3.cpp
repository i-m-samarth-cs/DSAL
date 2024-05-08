#include <iostream>
using namespace std;

// Define the structure of a node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to insert a new node into the binary search tree
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

// Function to find the number of nodes in the longest path
int longestPath(Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftDepth = longestPath(root->left);
    int rightDepth = longestPath(root->right);
    
    return max(leftDepth, rightDepth) + 1;
}

// Function to find the minimum data value in the tree
int findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to swap left and right pointers at every node
void swapNodes(Node* root) {
    if (root == NULL) {
        return;
    }
    
    swap(root->left, root->right);
    swapNodes(root->left);
    swapNodes(root->right);
}

// Function to search for a value in the tree
bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = NULL;
    int numNodes, value;

    cout << "Enter the number of nodes in the BST: ";
    cin >> numNodes;

    cout << "Enter the values of the BST: ";
    for (int i = 0; i < numNodes; i++) {
        cin >> value;
        root = insertNode(root, value);
    }
    
    // v. Search a value
    int searchValue;
    cout << "Enter a value to search in the BST: ";
    cin >> searchValue;
    cout << "Searching for value " << searchValue << ": ";
    if (search(root, searchValue)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    
    // ii. Find number of nodes in longest path
    cout << "Number of nodes in longest path: " << longestPath(root) << endl;
    
    // iii. Minimum data value found in the tree
    cout << "Minimum data value: " << findMin(root) << endl;
    
    // iv. Change a tree so that the roles of the left and right pointers are swapped at every node
    swapNodes(root);
    
    return 0;
}

