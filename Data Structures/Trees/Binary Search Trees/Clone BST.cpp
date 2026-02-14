// Time Complexity: O(n)
// Memory Complexity: O(n)
// Clone of a BST

BST *clone(BST *root)
{
    if (!root)
        return nullptr;

    BST *newNode = new BST(root->val);
    newNode->left = clone(root->left);
    newNode->right = clone(root->right);

    return newNode;
}
