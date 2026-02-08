// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// All nodes that are at a distance k from a given node

void collectFromSubTree(BT *root, ll k, ll depth, vector<ll> &kNodes)
{
    if (root == nullptr || depth > k)
    {
        return;
    }
    if (depth == k)
    {
        kNodes.push_back(root->val);
        return;
    }
    collectFromSubTree(root->left, k, depth + 1, kNodes);
    collectFromSubTree(root->right, k, depth + 1, kNodes);
    return;
}

ll dfs(BT *root, BT *target, ll k, vector<ll> &kNodes)
{
    if (root == nullptr)
    {
        return -1;
    }
    if (root == target)
    {
        collectFromSubTree(root, k, 0, kNodes);
        return 1;
    }

    ll left = dfs(root->left, target, k, kNodes);
    ll right = dfs(root->right, target, k, kNodes);

    if (left != -1)
    {
        if (left == k)
            kNodes.push_back(root->val);
        else
            collectFromSubTree(root->right, k, left + 1, kNodes);
        return left + 1;
    }
    if (right != -1)
    {
        if (right == k)
            kNodes.push_back(root->val);
        else
            collectFromSubTree(root->left, k, right + 1, kNodes);
        return right + 1;
    }
    return -1;
}

vector<ll> kDistance(BT *root, BT *target, ll k)
{
    vector<ll> kNodes;
    dfs(root, target, k, kNodes);
    return kNodes;
}
