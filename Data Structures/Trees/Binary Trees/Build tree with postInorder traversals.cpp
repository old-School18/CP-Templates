// Time Complexity: O(n)
// Memory Complexity: O(n)
// Build tree from post order and in order traversals


BT *buildTreeRecursive(vector<ll> &postorder, unordered_map<ll, ll> &inorderLookup, ll &postorderIdx, ll left, ll right)
{
    if (left > right)
    {
        return nullptr;
    }
    BT *node = new BT(postorder[postorderIdx--]);
    ll inorderIdx = inorderLookup[postorder[postorderIdx + 1]];
    node->right = buildTreeRecursive(postorder, inorderLookup, postorderIdx, inorderIdx + 1, right);
    node->left = buildTreeRecursive(postorder, inorderLookup, postorderIdx, left, inorderIdx - 1);
    return node;
}
BT *buildTree(vector<ll> &inorder, vector<ll> &postorder)
{

    unordered_map<ll, ll> inorderLookup;
    for (ll i = 0; i < inorder.size(); i++)
    {
        inorderLookup[inorder[i]] = i;
    }
    ll postorderIdx = postorder.size() - 1;
    return buildTreeRecursive(postorder, inorderLookup, postorderIdx, 0, inorder.size() - 1);
}
