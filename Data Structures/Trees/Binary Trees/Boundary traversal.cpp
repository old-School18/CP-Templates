// Time Complexity: O(n)
// Memory Complexity: O(h) where h = tree height
// Boundary of a binary tree

void boundaryBTRecurse(BT *root, bool isLeftBoundary, bool isRightBoundary, vector<ll> &boundary)
{
    if (root == nullptr)
    {
        return;
    }

    bool isLeafNode = !root->left && !root->right;
    if ((isLeftBoundary && !isLeafNode) || isLeafNode)
    {
        boundary.push_back(root->data);
    }

    boundaryBTRecurse(root->left, isLeftBoundary, isRightBoundary && !root->right, boundary);
    boundaryBTRecurse(root->right, isLeftBoundary && !root->left, isRightBoundary, boundary);

    if (isRightBoundary && !isLeafNode)
    {
        boundary.push_back(root->data);
    }
}
vector<ll> boundaryBT(BT *root)
{
    vector<ll> boundary;
    if (root == nullptr)
    {
        return boundary;
    }
    boundary.push_back(root->data);
    boundaryBTRecurse(root->left, true, false, boundary);
    boundaryBTRecurse(root->right, false, true, boundary);

    return boundary;
}
