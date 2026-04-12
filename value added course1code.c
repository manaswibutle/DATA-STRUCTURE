/* Name-Manaswi Butle 
   /PRN-25070521224/
   SECTION-D-II
   Value Added Problem-1 */
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
        if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}
void printInRange(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    if (root->data > low)
        printInRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data < high)
        printInRange(root->right, low, high);
}
int main() {
    struct Node* root = NULL;

    root = insert(root, 17);
    insert(root, 4);
    insert(root, 18);
    insert(root, 2);
    insert(root, 9);
    int low = 4, high = 24;
    printf("Output: ");
    printInRange(root, low, high);

    return 0;
}
