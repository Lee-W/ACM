#include <cstdio>
#define maxNodeNum 10005

struct Node {
    Node* left;
    Node* right;
    int value;

    Node() {
        left = NULL;
        right = NULL;
    }
};

void postOrderTraversal(Node*);
void buildTree(Node*&,int,int);

int preOrderResult[maxNodeNum];
main()
{
    int counter = 0;
    while(scanf("%d", &preOrderResult[counter]) == 1)
        counter++;

    Node* root;
    buildTree(root, 0, counter);
    postOrderTraversal(root);

}

void buildTree(Node*& root,int start, int end) {
    root  = new Node();
    root->value = preOrderResult[start];
    int leftStart = start + 1, rightStart = end;

    for (int i = start; i < end; i++)
        if (root->value < preOrderResult[i]) {
            rightStart = i;
            break;
        }

    if (leftStart != rightStart)
        buildTree(root->left, leftStart, rightStart);

    if (rightStart != end)
        buildTree(root->right, rightStart, end);
}

void postOrderTraversal(Node* c) {
    if (c->left != NULL)
        postOrderTraversal(c->left);
    
    if (c->right != NULL)
        postOrderTraversal(c->right);
    printf("%d\n", c->value);
}
