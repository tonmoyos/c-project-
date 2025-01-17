//Name : Tanmay Roy Rony
// ID  : 23-51745-2
// Section: [A]

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
    Student* left;
    Student* right;

    Student(int studentId, string studentName, float studentCgpa)
        : id(studentId), name(studentName), cgpa(studentCgpa), left(nullptr), right(nullptr) {}
};
class BinarySearchTree {
private:
    Student* root;
    Student* recentStudent;
Student* insert(Student* node, int id, string name, float cgpa){
        if (node == nullptr){
            Student* newStudent = new Student(id, name, cgpa);
            recentStudent = newStudent;
            return newStudent;
            }
        if (id < node->id){
            node->left = insert(node->left, id, name, cgpa);
        } else if (id > node->id){
            node->right = insert(node->right, id, name, cgpa);
        }
        return node;
    }

    void inorderTraversal(Student* node){
        if (node != nullptr){
            inorderTraversal(node->left);
            cout << "ID: " << node->id << ", Name: " << node->name << ", CGPA: " << node->cgpa << endl;
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(Student* node){
        if (node != nullptr){
            cout << "ID: " << node->id << ", Name: " << node->name << ", CGPA: " << node->cgpa << endl;
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(Student* node){
        if (node != nullptr){
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << "ID: " << node->id << ", Name: " << node->name << ", CGPA: " << node->cgpa << endl;
        }
    }

    Student* search(Student* node, int id){
        if (node == nullptr || node->id == id){
            return node;
        }
        if (id < node->id){
            return search(node->left, id);
        } else {
            return search(node->right, id);
        }
    }

    Student* findMin(Student* node){
        while (node->left != nullptr)
            {
            node = node->left;
        }
        return node;
    }

    Student* deleteNode(Student* node, int id)
    {
        if (node == nullptr){
            return node;
        }
        if (id < node->id){
            node->left = deleteNode(node->left, id);
        } else if (id > node->id){
            node->right = deleteNode(node->right, id);
        } else{

            if (node->left == nullptr && node->right == nullptr){
                delete node;
                return nullptr;
            }

            else if (node->left == nullptr){
                Student* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr){
                Student* temp = node->left;
                delete node;
                return temp;
            }

            else

                {
                Student* temp = findMin(node->right);
                node->id = temp->id;
                node->name = temp->name;
                node->cgpa = temp->cgpa;
                node->right = deleteNode(node->right, temp->id);
            }
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr), recentStudent(nullptr){}

    void insert(int id, string name, float cgpa){
        root = insert(root, id, name, cgpa);
    }

    void inorder() {
        cout << "Inorder Traversal:" << endl;
        inorderTraversal(root);
    }

    void preorder() {
        cout << "Preorder Traversal:" << endl;
        preorderTraversal(root);
    }

    void postorder() {
        cout << "Postorder Traversal:" << endl;
        postorderTraversal(root);
    }

    void search(int id) {
        Student* result = search(root, id);
        if (result != nullptr) {
            cout << "Student Found: ID: " << result->id << ", Name: " << result->name << ", CGPA: " << result->cgpa << endl;
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void deleteNode(int id) {
        root = deleteNode(root, id);
    }

    void showRecentStudent() {
        if (recentStudent != nullptr) {
            cout << "Most Recent Student Added: ID: " << recentStudent->id << ", Name: " << recentStudent->name << ", CGPA: " << recentStudent->cgpa << endl;
        } else {
            cout << "No students have been added yet." << endl;
        }
    }
};

int main() {
    BinarySearchTree bst;
    int choice, id;
    string name;
    float cgpa;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Student\n";
        cout << "2. Display Inorder Traversal\n";
        cout << "3. Display Preorder Traversal\n";
        cout << "4. Display Postorder Traversal\n";
        cout << "5. Search Student\n";
        cout << "6. Delete Student\n";
        cout << "7. Show Most Recent Student\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Student Name: ";
                getline(cin, name);
                cout << "Enter Student CGPA: ";
                cin >> cgpa;
                bst.insert(id, name, cgpa);
                break;
            case 2:
                bst.inorder();
                break;
            case 3:
                bst.preorder();
                break;
            case 4:
                bst.postorder();
                break;
            case 5:
                cout << "Enter Student ID to Search: ";
                cin >> id;
                bst.search(id);
                break;
            case 6:
                cout << "Enter Student ID to Delete: ";
                cin >> id;
                bst.deleteNode(id);
                break;
            case 7:
                bst.showRecentStudent();
                break;
            case 8:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
