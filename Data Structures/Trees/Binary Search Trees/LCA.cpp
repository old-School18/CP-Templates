// Time Complexity: O(h) where h = tree height
// Memory Complexity: O(h) Recursive | O(1) Iterative
// LCA

// Recursive
BST *LCARecursive(BST *root, BST *a, BST *b)
{
    if (root == nullptr)
        return root;
    if (root->data > a->data && root->data > b->data)
        return LCARecursive(root->left, a, b);
    if (root->data < a->data && root->data < b->data)
        return LCARecursive(root->right, a, b);

    return root;
}


-----------------
// Iterative
BST *LCA(BST *root, BST *a, BST *b)
{
    while (root && (root->data - a->data) * (root->data - b->data) > 0)
    {
        root = (root->data > a->data) ? root->left : root->right;
    }
    return root;
}
