// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Remove all half nodes

BT *halfNodeRemoval(BT *root)
{
    if (!root)
        return nullptr;
    root->left = halfNodeRemoval(root->left);
    root->right = halfNodeRemoval(root->right);
    if (root->left == nullptr && root->right == nullptr)
        return root;
    if (root->left == nullptr)
        return root->right;
    if (root->right == nullptr)
        return root->left;

    return root;
}
