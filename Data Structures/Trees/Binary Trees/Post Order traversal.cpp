// Time Complexity: O(n)
// Memory Complexity: O(h) where h = height of the tree
// Pre order traversal of a binary tree

// Recursive
void postOrderRecurse(BT *root, vector<ll> &postOrderNodes)
{
    if (root)
    {
        postOrderNodes.push_back(root->data);
        postOrderRecurse(root->right);
        postOrderRecurse(root->left);
    }
    return;
}

vector<ll> postOrder(BT *root)
{
    vector<ll> postOrderNodes;
    postOrderRecurse(root, postOrderNodes);
    reverse(postOrderNodes.begin(), postOrderNodes.end());
    return postOrderNodes;
}

---------------------
// Iterative
vector<ll> postOrder(BT *root)
{
    vector<ll> postOrderNodes;
    stack<BT *> stk;

    if (root)
    {
        stk.push(root);
    }

    while (!stk.empty())
    {
        auto p = stk.top();
        stk.pop();

        postOrderNodes.push_back(p->data);

        if (p->left)
        {
            stk.push(p->left);
        }
        if (p->right)
        {
            stk.push(p->right);
        }
    }
    
    
    reverse(postOrderNodes.begin(), postOrderNodes.end());
    return postOrderNodes;
}
