// Time Complexity: O(n)
// Memory Complexity: O(h) where h = height of the tree
// In order traversal of a binary tree

// Recursive
void inOrderRecurse(BT *root, vector<ll> &inOrderNodes)
{
    if (root)
    {
        inOrderRecurse(root->left);
        inOrderRecurse.push_back(root->data);
        inOrderRecurse(root->right);
    }
    return;
}

vector<ll> inOrder(BT *root)
{
    vector<ll> inOrderNodes;
    inOrderRecurse(root, inOrderNodes);
    return inOrderNodes;
}

---------------------
// Iterative
vector<ll> inOrder(BT *root)
{
    vector<ll> inOrderNodes;
    stack<BT *> stk;
    BT *curr = root;

    while (curr != nullptr || !stk.empty())
    {
        while (curr != nullptr)
        {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();
        inOrderNodes.push_back(curr->data);
        curr = curr->right;
    }

    return inOrderNodes;
}
