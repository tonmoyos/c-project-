//  Name : Tanmay Roy Rony
//  ID   : 23-51745-2
//  Sec  : [A]


#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int data) : key(data), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key)
{
    if (root == nullptr)
        {
        return new Node(key);
    }
    if (key < root->key)
     {
        root->left = insert(root->left, key);
    } else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node* root)
 {
    if (root != nullptr)
        {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node* root)
{
    if (root != nullptr)
        {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root)
 {
    if (root != nullptr)
        {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}



bool search(Node* root, int key)
 {
    if (root == nullptr)
        {
        return false;
    }
    if (root->key == key)
     {
        return true;
    }
    if (key < root->key)
    {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}



int main()
 {
    Node* root = nullptr;
    int choice, key;

    while (true)
        {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Pre-order Traversal\n";
        cout << "4. Post-order Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the key to insert: ";
                cin >> key;
                root = insert(root, key);
                cout << "Key inserted.\n";
                break;
            case 2:
                cout << "In-order Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Pre-order Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Post-order Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter the key to search: ";
                cin >> key;
                if (search(root, key)) {
                    cout << "Key found in the BST.\n";
                } else {
                    cout << "Key not found in the BST.\n";
                }
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
