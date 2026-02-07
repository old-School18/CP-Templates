// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Check if a binary tree is symmetric i.e., left and right descendants of the root node are mirror images of each other

bool isSymmetricTreeRecurse(BT *root1, BT *root2)
{
    if (root1 == nullptr || root2 == nullptr)
    {
        return root1 == root2;
    }
    return (root1->val == root2->val && isSymmetricTreeRecurse(root1->left, root2->right) &&
            isSymmetricTreeRecurse(root1->right, root2->left));
}

bool isSymmetric(BT *root)
{
    if (root == nullptr)
    {
        return true;
    }
    return isSymmetricTreeRecurse(root->left, root->right);
}
