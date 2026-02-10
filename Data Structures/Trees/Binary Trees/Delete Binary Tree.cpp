// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Delete complete binary tree

void deleteBT(BT *root)
{
    if (root == NULL)
        return;
    deleteBT(root->left);
    deleteBT(root->right);
    delete(root);
}
