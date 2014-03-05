#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    char content;
    Node() {
        left = NULL;
        right = NULL;
    };
};

Node* buildTree(string, string);
void postOrderTraversal(Node*);
void deleteTree(Node*);

main()
{
    ios::sync_with_stdio(false);
    string preorderTree, inorderTree;

    while(cin >> preorderTree >> inorderTree) {
        Node* root = buildTree(preorderTree, inorderTree);
        postOrderTraversal(root);
        cout << endl;
        deleteTree(root);
    }
}

Node* buildTree(string preorderTree, string inorderTree) {
    Node* root = new Node();
    root->content = preorderTree[0];

    int treeSize = preorderTree.size();
    int inorderRootIndex, preorderRightRootIndex = -1;

    for (int i = 0; i < treeSize; i++)
        if (inorderTree[i] == root->content) {
            inorderRootIndex = i;
            break;
        }
    for (int i = 1; i < treeSize; i++)
        if (inorderTree.find(preorderTree[i])> inorderRootIndex && inorderTree.find(preorderTree[i]) < treeSize) {
            preorderRightRootIndex = i;
            break;
        }

    if (inorderRootIndex > 0)
        root->left = buildTree(preorderTree.substr(1, preorderRightRootIndex-1), inorderTree.substr(0, inorderRootIndex));
    if (inorderRootIndex < treeSize-1 && preorderRightRootIndex != -1)
        root->right = buildTree(preorderTree.substr(preorderRightRootIndex), inorderTree.substr(inorderRootIndex+1));
    return root;
}

void postOrderTraversal(Node* root) {
    if (root->left != NULL)
        postOrderTraversal(root->left);
    if (root->right != NULL)
        postOrderTraversal(root->right);
    cout << root->content;
}

void deleteTree(Node* root) {
    if (root->left != NULL)
        deleteTree(root->left);
    else if (root->right != NULL)
        deleteTree(root->right);
    delete root;
}
