// Time Complexity: O(n)
// Memory Complexity: O(n)
// Build tree from pre order and in order traversals


BT *buildTreeRecursive(vector<ll> &preorder, unordered_map<ll, ll> &inorderLookup, ll &preOrderIdx, ll left, ll right)
{
    if (left > right)
    {
        return nullptr;
    }
    BT *node = new BT(preorder[preOrderIdx++]);
    ll inorderIdx = inorderLookup[preorder[preOrderIdx - 1]];
    node->left = buildTreeRecursive(preorder, inorderLookup, preOrderIdx, left, inorderIdx - 1);
    node->right = buildTreeRecursive(preorder, inorderLookup, preOrderIdx, inorderIdx + 1, right);
    return node;
}

BT *buildTree(vector<ll> &preorder, vector<ll> &inorder)
{
    unordered_map<ll, ll> inorderLookup;
    for (ll i = 0; i < inorder.size(); i++)
    {
        inorderLookup[inorder[i]] = i;
    }
    ll preorderIdx = 0;
    return buildTreeRecursive(preorder, inorderLookup, preorderIdx, 0, inorder.size() - 1);
}
