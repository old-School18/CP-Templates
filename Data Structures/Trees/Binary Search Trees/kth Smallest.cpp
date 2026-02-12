// Time Complexity: O(h) where h = tree height
// Memory Complexity: O(1) Iterative | O(h) Recursive
// kth Smallest Node  (In order traversal)

// Recursive
void kthSmallestRecurse(BST *root, ll k, ll &idx, ll &kth)
{
    if (!root || idx >= k)
    {
        return;
    }
    kthSmallestRecurse(root->left, k, idx, kth);
    if (++idx == k)
    {
        kth = root->val;
        return;
    }
    kthSmallestRecurse(root->right, k, idx, kth);
}

ll kthSmallest(BST *root, ll k)
{
    ll idx = 0;
    ll kth = -1;
    kthSmallestRecurse(root, k, idx, kth);
    return kth;
}


----------------
// Iterative
ll kthSmallest(BST *root, ll k)
{
    ll idx = 0;
    stack<BST *> stk;
    while (root != nullptr || !stk.empty())
    {
        while (root != nullptr)
        {
            stk.push(root);
            root = root->left;
        }

        root = stk.top();
        stk.pop();
        if (++idx == k)
        {
            return root->val;
        }
        root = root->right;
    }
    return -1;
}
