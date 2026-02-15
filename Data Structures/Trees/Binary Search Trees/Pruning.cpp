// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Prune all nodes in a BST that are outside a given range

BST *prune(BST *root, ll low, ll high)
{
    if (!root)
        return nullptr;

    if (root->data < low)
        return prune(root->right, low, high);

    if (root->data > high)
        return prune(root->left, low, high);

    root->left = prune(root->left, low, high);
    root->right = prune(root->right, low, high);

    return root;
}
