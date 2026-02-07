// Time Complexity: O(n)
// Memory Complexity: O(h) where h = height of the tree
// Height of a binary tree

// Recursive
ll heightBTRecursive(BT *root)
{
    if (!root)
    {
        return 0;
    }

    return 1ll + max(heightBTRecursive(root->left), heightBTRecursive(root->right));
}

------------------------
// Iterative
ll heightBT(BT *root)
{
    ll height = 0;
    stack<pair<BT *, ll>> stk;

    if (root)
    {
        stk.push({root, 1});
    }

    while (!stk.empty())
    {
        auto p = stk.top();
        stk.pop();
        height = max(height, p.second);

        if (p.first->right)
        {
            stk.push({p.first->right, p.second + 1});
        }
        if (p.first->left)
        {
            stk.push({p.first->left, p.second + 1});
        }
    }
    return height;
}
