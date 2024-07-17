#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BST {
public:
    Node* root;

    BST() : root(NULL) {}

    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    Node* search(Node* node, int val) {
        if (node == NULL || node->data == val) {
            return node;
        }
        if (val < node->data) {
            return search(node->left, val);
        }
        return search(node->right, val);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* root, int val) {
        if (root == NULL) return root;

        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inOrder(Node* node) {
        if (node == NULL) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == NULL) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BST tree;
    int values[] = {10, 14, 89, 22, 59, 30, 90};
    for (int i = 0; i < 7; ++i) {
        tree.root = tree.insert(tree.root, values[i]);
    }

    cout << "InOrder traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "PreOrder traversal: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "PostOrder traversal: ";
    tree.postOrder(tree.root);
    cout << endl;

    cout << "Search for 14: " << (tree.search(tree.root, 14) ? "Found" : "Not Found") << endl;

    cout << "Delete 90\n";
    tree.deleteNode(tree.root, 90);
    cout << "InOrder traversal after deletion: ";
    tree.inOrder(tree.root);
    cout << endl;

    return 0;
}

