// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Ancestors of a node

bool ancestorsRecurse(BT *root, BT *target, vector<ll> &ancestorNodes)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->left == target || root->right == target || ancestorsRecurse(root->left, target, ancestorNodes) ||
        ancestorsRecurse(root->right, target, ancestorNodes))
    {
        ancestorNodes.push_back(root->data);
        return true;
    }
    return false;
}

vector<ll> ancestors(BT *root, BT *target)
{
    vector<ll> ancestorNodes;
    ancestorsRecurse(root, target, ancestorNodes);
    return ancestorNodes;
}
