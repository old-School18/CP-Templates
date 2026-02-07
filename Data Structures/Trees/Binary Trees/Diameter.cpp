// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Diameter of a binary tree - length of the longest path between any 2 nodes

ll diameterBTRecurse(BT *root, ll &diameter)
{
    if (root == nullptr)
    {
        return 0;
    }

    ll leftHeight = diameterBTRecurse(root->left, diameter);
    ll rightHeight = diameterBTRecurse(root->right, diameter);

    diameter = max(diameter, leftHeight + rightHeight);
    return 1ll + max(leftHeight, rightHeight);
}

ll diameterOfBinaryTree(BT *root)
{
    ll diameter = 0;
    diameterBTRecurse(root, diameter);
    return diameter;
}
