// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Lowest common ancestor of two nodes in a binary tree

// Existence of both nodes guaranteed
BT *lca(BT *root, BT *p, BT *q)
{
    if (root == nullptr || root == p || root == q)
    {
        return root;
    }
    auto left = lca(root->left, p, q);
    auto right = lca(root->right, p, q);
    if (left && right)
    {
        return root;
    }
    return left ? left : right;
}

----------------
// Existence of both nodes not guaranteed
BT *lcaRecurse(BT *root, BT *p, BT *q, ll &found)
{
    if (root == nullptr)
    {
        return root;
    }
    auto left = lcaRecurse(root->left, p, q, found);
    auto right = lcaRecurse(root->right, p, q, found);

    if (root == p || root == q)
    {
        found++;
        return root;
    }

    if (left && right)
    {
        return root;
    }
    return left ? left : right;
}

BT *lca(BT *root, BT *p, BT *q)
{
    ll found = 0;
    BT *lowestCommonAncestor = lcaRecurse(root, p, q, found);
    return (found == 2) ? lowestCommonAncestor : nullptr;
}
