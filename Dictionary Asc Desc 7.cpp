#include <iostream>
#include <string>
using namespace std;

class node {
    string word, meaning;
    node *left, *right;

public:
    friend class dictionary;
    node() {
        left = NULL;
        right = NULL;
    }
    node(string word, string meaning) {
        this->word = word;
        this->meaning = meaning;
        left = NULL;
        right = NULL;
    }
};

class dictionary {
    node *root;

public:
    dictionary() {
        root = NULL;
    }
    void create();
    void inorder_rec(node *rnode);
    void postorder_rec(node *rnode);
    void inorder() {
        inorder_rec(root);
    }
    void postorder();
    bool insert(string word, string meaning);
    int search(string key);
};

// Function to search for a word in the dictionary
int dictionary::search(string key) {
    node *tmp = root;
    int count = 0; // Initialize count for comparisons

    if (tmp == NULL) {
        return -1; // Dictionary is empty
    }

    while (tmp != NULL) {
        count++; // Increment comparison count

        if (tmp->word == key) {
            return count; // Word found, return comparison count
        } else if (tmp->word > key) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    return -1; // Word not found in the dictionary
}

// Function to display words and meanings in descending order
void dictionary::postorder() {
    postorder_rec(root);
}

void dictionary::postorder_rec(node *rnode) {
    if (rnode) {
        postorder_rec(rnode->right);
        cout << " " << rnode->word << " : " << rnode->meaning << endl;
        postorder_rec(rnode->left);
    }
}

// Function to create the dictionary
void dictionary::create() {
    int n;
    string wordI, meaningI;
    cout << "\nHow many words to insert?: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character left in the input buffer

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Word: ";
        getline(cin, wordI); // Read the entire line including whitespaces
        cout << "Enter Meaning: ";
        getline(cin, meaningI); // Read the entire line including whitespaces
        insert(wordI, meaningI);
    }
}

// Function to display words and meanings in ascending order
void dictionary::inorder_rec(node *rnode) {
    if (rnode) {
        inorder_rec(rnode->left);
        cout << " " << rnode->word << " : " << rnode->meaning << endl;
        inorder_rec(rnode->right);
    }
}

// Function to insert a word and its meaning into the dictionary
bool dictionary::insert(string word, string meaning) {
    node *p = new node(word, meaning);
    if (root == NULL) {
        root = p;
        return true; // Insertion successful
    }
    node *cur = root;
    node *par = root;

    while (cur != NULL) {
        if (word > cur->word) {
            par = cur;
            cur = cur->right;
        } else if (word < cur->word) {
            par = cur;
            cur = cur->left;
        } else {
            cout << "\nWord is already in the dictionary.";
            delete p; // Avoid memory leak
            return false; // Word already exists
        }
    }

    if (word > par->word) {
        par->right = p; // Insert as right child
    } else {
        par->left = p; // Insert as left child
    }
    return true; // Insertion successful
}

int main() {
    string word;
    dictionary months;
    months.create();

    cout << "\nWords in Ascending Order:\n";
    months.inorder();

    cout << "\nWords in Descending Order:\n";
    months.postorder();

    cout << "\nEnter a word to search: ";
    cin >> word;
    int comparisons = months.search(word);
    if (comparisons == -1) {
        cout << "\nThe word \"" << word << "\" is not found in the dictionary.\n";
    } else {
        cout << "\nThe word \"" << word << "\" is found in the dictionary in " << comparisons << " comparisons.\n";
    }
    return 0;
}

