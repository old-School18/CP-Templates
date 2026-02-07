// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Check if a binary tree is balanced or not

ll isBalancedBTRecurse(BT *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    ll leftHeight = isBalancedBTRecurse(root->left);
    if (leftHeight == -1)
        return -1;
    ll rightHeight = isBalancedBTRecurse(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return 1ll + max(leftHeight, rightHeight);
}

bool isBalancedBT(BT *root)
{
    return isBalancedBTRecurse(root) != -1;
}
