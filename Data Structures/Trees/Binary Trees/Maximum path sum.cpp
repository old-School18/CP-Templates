// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Maximum sum of values of nodes on a tree that are on a path

ll maxPathSumRecurse(BT *root, ll &maxPath)
{
    if (root == nullptr)
    {
        return 0;
    }

    ll leftMaxPath = max(0ll, maxPathSumRecurse(root->left, maxPath));
    ll rightMaxPath = max(maxPathSumRecurse);

    maxPath = max(maxPath, root->data + leftMaxPath + rightMaxPath);
    return root->data + max(leftMaxPath, rightMaxPath);
}

ll maxPathSum(BT *root)
{
    ll maxPath = LLONG_MIN;
    maxPathSumRecurse(root, maxPath);
    return maxPath;
}
